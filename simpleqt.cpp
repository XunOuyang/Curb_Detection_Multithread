//*********************************************************************************************
// Copyright 2014 ON Semiconductor.  This software and/or documentation is provided by 
// ON Semiconductor under limited terms and conditions.  
// The terms and conditions pertaining to the software and/or documentation are available at 
// www.onsemi.com ("ON Semiconductor Standard Terms and Conditions of Sale, Section 8 Software").  
// Do not use this software and/or documentation unless you have carefully read and you agree 
// to the limited terms and conditions.  
// By using this software and/or documentation, you agree to the limited terms and conditions. 
//*********************************************************************************************

#include "simpleqt.h"
#include "callbacks.h"

#include <iostream>

#if QT_VERSION > 0x050000
#include <QMessageBox>
#else
#include <QtGui/QMessageBox>
#endif

#if QT_VERSION > 0x050000
SimpleQt::SimpleQt(QWidget *parent, Qt::WindowFlags flags)
#else
SimpleQt::SimpleQt(QWidget *parent, Qt::WFlags flags)
#endif
    : QMainWindow(parent, flags),
    m_dockInfo(NULL),
    m_dlgInfo(NULL),
    m_hApBase(NULL),
	m_bRecording(0),
    m_bPlaying(0),
    m_nWidth(0),
    m_nHeight(0),
	cam_amount(-1)
{
    ui.setupUi(this);
    createActions();
    createMenus();
    createToolbars();
	for (int i = 0; i < 3; i++)
	{
		m_viewPixmap[i] = NULL;
	}

	int_image[0].load("1.jpg");
	int_image[1].load("2.jpg");
	int_image[2].load("3.jpg");

	this->m_scene[0] = new QGraphicsScene(this);
	ui.graphicsView_left->setScene(m_scene[0]);
	m_stream_left = m_scene[0]->addPixmap(int_image[0]);

	this->m_scene[1] = new QGraphicsScene(this);
	ui.graphicsView_right->setScene(m_scene[1]);
	m_stream_right = m_scene[1]->addPixmap(int_image[1]);

	this->m_scene[2] = new QGraphicsScene(this);
	ui.graphicsView_center->setScene(m_scene[2]);
	m_stream_center = m_scene[2]->addPixmap(int_image[2]);
}

SimpleQt::~SimpleQt()
{
}

void SimpleQt::createActions()
{
    m_playAct = new QAction(QIcon("C:/Users/csav4/Desktop/SimpleQt/SimpleQt/Resources/media_play.ico"), tr("&Play"), this);
    m_playAct->setStatusTip(tr("Turn on image streaming"));
    m_playAct->setCheckable(true);
    connect(m_playAct, SIGNAL(triggered()), this, SLOT(onPlay()));

    m_stopAct = new QAction(QIcon("C:/Users/csav4/Desktop/SimpleQt/SimpleQt/Resources/media_stop.ico"), tr("&Stop"), this);
    m_stopAct->setStatusTip(tr("Turn off image streaming"));
    m_stopAct->setCheckable(true);
    connect(m_stopAct, SIGNAL(triggered()), this, SLOT(onStop()));


	m_startRecord = new QAction(QIcon("C:/Users/csav4/Desktop/SimpleQt/SimpleQt/Resources/start_record.ico"), tr("&Start_Record"), this);
	m_startRecord->setStatusTip(tr("Turn on image rerocding"));
	m_startRecord->setCheckable(true);
	connect(m_startRecord, SIGNAL(triggered()), this, SLOT(startRecord()));

	m_stopRecord = new QAction(QIcon("C:/Users/csav4/Desktop/SimpleQt/SimpleQt/Resources/stop_record.ico"), tr("&Stop_Record"), this);
	m_stopRecord->setStatusTip(tr("Turn off image recording"));
	m_stopRecord->setCheckable(true);
	connect(m_stopRecord, SIGNAL(triggered()), this, SLOT(stopRecord()));


    m_exitAct = new QAction(QIcon("../SimpleQt/Resources/exit.ico"), tr("&Exit"), this);
    m_exitAct->setShortcuts(QKeySequence::Quit);
    m_exitAct->setStatusTip(tr("Exit the application"));
    connect(m_exitAct, SIGNAL(triggered()), qApp, SLOT(closeAllWindows()));

    m_viewToolbarAct = new QAction(tr("Toolbar"), this);
    m_viewToolbarAct->setStatusTip(tr("Show or hide the toolbar"));
    m_viewToolbarAct->setCheckable(true);
    m_viewToolbarAct->setChecked(true);
    connect(m_viewToolbarAct, SIGNAL(triggered()), this, SLOT(toggleToolbar()));

	
    m_viewCtrlbarAct = new QAction(QIcon("../SimpleQt/Resources/gear.ico"), tr("Control Bar"), this);
    m_viewCtrlbarAct->setStatusTip(tr("Show or hide the register control bar"));
    m_viewCtrlbarAct->setCheckable(true);
    m_viewCtrlbarAct->setChecked(true);
    connect(m_viewCtrlbarAct, SIGNAL(triggered()), this, SLOT(toggleCtrlbar()));
	

    m_aboutAct = new QAction(QIcon("../SimpleQt/Resources/about.ico"), tr("&About"), this);
    m_aboutAct->setStatusTip(tr("Show the application's About box"));
    connect(m_aboutAct, SIGNAL(triggered()), this, SLOT(about()));
}

void SimpleQt::createMenus()
{
    m_fileMenu = menuBar()->addMenu(tr("&File"));
    m_fileMenu->addAction(m_exitAct);

    m_viewMenu = menuBar()->addMenu(tr("&View"));
    m_viewMenu->addAction(m_playAct);
    m_viewMenu->addAction(m_stopAct);
    m_viewMenu->addSeparator();
    m_viewMenu->addAction(m_viewToolbarAct);
    m_viewMenu->addAction(m_viewCtrlbarAct);

    m_helpMenu = menuBar()->addMenu(tr("&Help"));
    m_helpMenu->addAction(m_aboutAct);
}

void SimpleQt::createToolbars()
{
    ui.mainToolBar->addAction(m_playAct);
    ui.mainToolBar->addAction(m_stopAct);
    ui.mainToolBar->addSeparator();


	ui.mainToolBar->addAction(m_startRecord);
	ui.mainToolBar->addAction(m_stopRecord);
	ui.mainToolBar->addSeparator();


    ui.mainToolBar->addAction(m_viewCtrlbarAct);
    ui.mainToolBar->addAction(m_aboutAct);
	ui.mainToolBar->addAction(m_exitAct);
}

void SimpleQt::closeEvent(QCloseEvent *event)
{
    onStop();
    ap_Destroy(m_hApBase[0]);
} 

void SimpleQt::about()
{
    QMessageBox about(this);
    about.setWindowTitle("About SimpleQt");
    about.setText("The SimpleQt sample demonstrates a simple Qt GUI "
                "application based on the ON Semiconductor <b>ApBase API</b>.");
    about.setStandardButtons(QMessageBox::Ok);
    about.setDefaultButton(QMessageBox::Ok);
     
    QSpacerItem* horizontalSpacer = new QSpacerItem(500, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    QGridLayout* layout = (QGridLayout*)about.layout();
    layout->addItem(horizontalSpacer, layout->rowCount(), 0, 1, layout->columnCount());
    about.exec();

}

void SimpleQt::toggleToolbar()
{
    if (ui.mainToolBar->isVisible())
        ui.mainToolBar->hide();
    else
        ui.mainToolBar->show();
    m_viewToolbarAct->setChecked(ui.mainToolBar->isVisible());
}

void SimpleQt::toggleCtrlbar()
{
    if (m_dockInfo->isVisible())
        m_dockInfo->hide();
    else
        m_dockInfo->show();
    m_viewCtrlbarAct->setChecked(m_dockInfo->isVisible());
}

void SimpleQt::CreateInfoDlg()
{
    m_dlgInfo = new InfoDlg(this);
    m_dlgInfo->setCamera(m_hApBase[0]);
    m_dockInfo = new QDockWidget(tr("Control Bar"), this);
    m_dockInfo->setAllowedAreas(Qt::TopDockWidgetArea);
    m_dockInfo->setWidget(m_dlgInfo);
    addDockWidget(Qt::TopDockWidgetArea, m_dockInfo);
}

void SimpleQt::onFirstStartup()
{
	
    int retVal = ap_DeviceProbe(NULL);
    if (retVal != AP_CAMERA_SUCCESS)
    {
        QMessageBox msgBox;
        msgBox.setText("Unable to either detect a sensor or find a matching SDAT file.\nSimpleQT will close.");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.exec();
        close();
        return;
    }

	cam_amount = ap_NumCameras();
	for (int i = 0; i <= cam_amount; i++)
	{
		m_hApBase.push_back(ap_Create(i));
	}
	
    if (m_hApBase[0] == NULL)
    {
        QMessageBox msgBox;
        msgBox.setText("Camera initialization error! SimpleQT will close.");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.exec();
        close();
        return;
    }

    //  Callbacks for notifications that we will need
    ap_SetCallback_MultipleChoice(m_hApBase[0], MultipleChoice_Callback, this);
    ap_SetCallback_ErrorMessage(m_hApBase[0], ErrorMessage_Callback, this);
    ap_SetCallback_BeforeSetSensorReg(m_hApBase[0], BeforeSetSensorReg_Callback, this);
    ap_SetCallback_AfterSetSensorReg(m_hApBase[0], AfterSetSensorReg_Callback, this);

	for (int i = 0; i < cam_amount; i++)
	{
		// Xun Ouyang made modification on this section: 
		//  Initialize the sensor
		// 1mp: C:/Aptina Imaging/apps_data/AR0143AT-REV1.ini
		// 2mp: C:/Aptina Imaging/apps_data/AR0231AT-REV7.ini
		//ap_LoadIniPreset(m_hApBase[i], "C:/Aptina Imaging/apps_data/AR0231 Demo Init Parallel Full Resolution 74p25MHz.ini", "Demo Initilization");
		// AR0143 MARS HDR Default Startup Log 74p25MHz from 27MHz August 2017
		ap_LoadIniPreset(m_hApBase[i], "C:/Aptina Imaging/apps_data/AR0143 MARS HDR Default Startup Log 74p25MHz from 27MHz August 2017.ini", "Demo Initilization");
		ap_CheckSensorState(m_hApBase[i], 0);
	}
	
	/*
    //  Initialize the sensor
    ap_LoadIniPreset(m_hApBase, NULL, NULL);
    ap_CheckSensorState(m_hApBase, 0);
	*/
	
    CreateInfoDlg();
	toggleCtrlbar();
	toggleCtrlbar();
	m_startRecord->setChecked(m_bRecording);
	m_stopRecord->setChecked(!m_bRecording);
    onPlay();
}

void SimpleQt::onPlay()
{
    if (m_hApBase[0] == NULL)
        return;
	if (m_bPlaying == true)
	{
		m_playAct->setChecked(m_bPlaying);
		m_stopAct->setChecked(!m_bPlaying);
		return;
	}
    m_bPlaying = true;
	
    ap_GetImageFormat(m_hApBase[0], &m_nWidth, &m_nHeight, NULL, 0);

	for (int i = 0; i < cam_amount; i++)
	{
		if (m_viewPixmap[i] == NULL)
			m_viewPixmap[i] = m_scene[i]->addPixmap(QPixmap(640, 400));
	}
	
	for (int i = 0; i < cam_amount; i++)
	{
		m_TripleBuffer[i].Alloc(ap_GrabFrame(m_hApBase[i], NULL, 0));
		m_CameraThread[i] = new CCameraThread(m_hApBase[i], &(m_TripleBuffer[i]));
		m_DisplayThread[i] = new CDisplayThread(m_hApBase[i], &(m_TripleBuffer[i]));

		m_DisplayThread[i]->index = i;
		connect(m_DisplayThread[i], SIGNAL(drawPix(QImage *, int)), this, SLOT(showPixmap(QImage *, int)),
			Qt::BlockingQueuedConnection);
		m_CameraThread[i]->start();
		m_DisplayThread[i]->start();	
	}    
	m_playAct->setChecked(m_bPlaying);
	m_stopAct->setChecked(!m_bPlaying);
}


void SimpleQt::showPixmap(QImage *image, int index)
{
	m_viewPixmap[index]->setPixmap(QPixmap::fromImage(*image).scaled(640, 400));
	delete image;
}

void SimpleQt::onStop()
{
    if (m_hApBase[0] == NULL)
        return;
	if (m_bPlaying == false || m_bRecording == true)
	{
		m_playAct->setChecked(m_bPlaying);
		m_stopAct->setChecked(!m_bPlaying);
		return;
	}
    m_bPlaying = false;
	for (int i = 0; i < cam_amount; i++)
	{
		m_CameraThread[i]->stop();
		m_DisplayThread[i]->stop();
		m_CameraThread[i]->wait();
		while (!m_DisplayThread[i]->wait(10))
			qApp->processEvents(QEventLoop::ExcludeUserInputEvents);
		delete m_CameraThread[i];
		delete m_DisplayThread[i]; 
		if (m_viewPixmap[i])
			m_viewPixmap[i]->setPixmap(QPixmap());
	}    
    m_playAct->setChecked(m_bPlaying);
    m_stopAct->setChecked(!m_bPlaying);
}

void SimpleQt::startRecord()
{
	if (m_bRecording == true)
	{
		m_startRecord->setChecked(m_bRecording);
		m_stopRecord->setChecked(!m_bRecording);
		m_playAct->setChecked(m_bPlaying);
		m_stopAct->setChecked(!m_bPlaying);
		return;
	}		
	onStop();
	if (m_hApBase[0] == NULL)
		return;
	m_bPlaying = true;
	m_bRecording = true;

	ap_GetImageFormat(m_hApBase[0], &m_nWidth, &m_nHeight, NULL, 0);

	for (int i = 0; i < cam_amount; i++)
	{
		if (m_viewPixmap[i] == NULL)
			m_viewPixmap[i] = m_scene[i]->addPixmap(QPixmap(640, 400));
	}

	for (int i = 0; i < cam_amount; i++)
	{
		m_TripleBuffer[i].Alloc(ap_GrabFrame(m_hApBase[i], NULL, 0));
		m_CameraThread[i] = new CCameraThread(m_hApBase[i], &(m_TripleBuffer[i]));
		m_RecordThread[i] = new CRecordThread(m_hApBase[i], &(m_TripleBuffer[i]));

		m_RecordThread[i]->index = i;
		connect(m_RecordThread[i], SIGNAL(drawPix(QImage *, int)), this, SLOT(showPixmap(QImage *, int)),
			Qt::BlockingQueuedConnection);
		m_CameraThread[i]->start();
		m_RecordThread[i]->start();
	}
	m_startRecord->setChecked(m_bRecording);
	m_stopRecord->setChecked(!m_bRecording);
	m_playAct->setChecked(m_bPlaying);
	m_stopAct->setChecked(!m_bPlaying);
}

void SimpleQt::stopRecord()
{
	if (m_hApBase[0] == NULL)
		return;
	if (m_bPlaying == false || m_bRecording == false)
	{
		m_startRecord->setChecked(m_bRecording);
		m_stopRecord->setChecked(!m_bRecording);
		m_playAct->setChecked(m_bPlaying);
		m_stopAct->setChecked(!m_bPlaying);
		return;
	}		
	m_bRecording = false;
	m_bPlaying = false;
	for (int i = 0; i < cam_amount; i++)
	{
		m_CameraThread[i]->stop();
		m_RecordThread[i]->stop();
		m_CameraThread[i]->wait();
		while (!m_RecordThread[i]->wait(10))
			qApp->processEvents(QEventLoop::ExcludeUserInputEvents);
		delete m_CameraThread[i];
		delete m_RecordThread[i];
		if (m_viewPixmap[i])
			m_viewPixmap[i]->setPixmap(QPixmap());
	}
	m_startRecord->setChecked(m_bRecording);
	m_stopRecord->setChecked(!m_bRecording);
	m_playAct->setChecked(m_bPlaying);
	m_stopAct->setChecked(!m_bPlaying);
}

/*
void SimpleQt::setHandle(AP_HANDLE hApBase)
{
	m_hApBase = hApBase;
}

AP_HANDLE SimpleQt::getHandle()
{
	return m_hApBase;
}
*/