//*********************************************************************************************
// Copyright 2014 ON Semiconductor.  This software and/or documentation is provided by 
// ON Semiconductor under limited terms and conditions.  
// The terms and conditions pertaining to the software and/or documentation are available at 
// www.onsemi.com ("ON Semiconductor Standard Terms and Conditions of Sale, Section 8 Software").  
// Do not use this software and/or documentation unless you have carefully read and you agree 
// to the limited terms and conditions.  
// By using this software and/or documentation, you agree to the limited terms and conditions. 
//*********************************************************************************************

#ifndef SIMPLEQT_H
#define SIMPLEQT_H

#include <QDockWidget>
#include <QGraphicsView>
#include "apbase.h"
#include "ui_simpleqt.h"
#include "CCameraThread.h"
#include "CDisplayThread.h"
#include "CRecordThread.h"
#include "infodlg.h"
#if QT_VERSION > 0x050000
#include <QMainWindow>
#else
#include <QtGui/QMainWindow>
#endif



using namespace std;

class SimpleQt : public QMainWindow
{
    Q_OBJECT

public:
#if QT_VERSION > 0x050000
    SimpleQt(QWidget *parent = 0, Qt::WindowFlags flags = 0);
#else
	SimpleQt(QWidget *parent = 0, Qt::WFlags flags = 0);
#endif
    ~SimpleQt();

protected:
    void            createActions();
    void            createMenus();
    void            createToolbars();
    void            closeEvent(QCloseEvent *event);

public slots:
    void            about();
    void            toggleToolbar();
    void            toggleCtrlbar();
    void            onFirstStartup();
    void            CreateInfoDlg();
    void            onPlay();
    void            onStop();
	void            showPixmap(QImage *, int );
	// The code below is commented by Xun Ouyang
	/*
	void			setHandle(AP_HANDLE hApBase);
	AP_HANDLE       getHandle();
	*/
	// Comment ends


	void			startRecord();
	void			stopRecord();


public:
    QMenu *             m_fileMenu;
    QMenu *             m_viewMenu;
    QMenu *             m_helpMenu;
    QAction *           m_playAct;
    QAction *           m_stopAct;
    QAction *           m_exitAct;
    QAction *           m_viewToolbarAct;
    QAction *           m_viewCtrlbarAct;
    QAction *           m_aboutAct;

    QGraphicsScene *    m_scene[3];

	QGraphicsPixmapItem * m_stream_left;
	QGraphicsPixmapItem * m_stream_center;
	QGraphicsPixmapItem * m_stream_right;


	QAction *			m_startRecord;
	QAction *			m_stopRecord;
	QPixmap				int_image[3];


private:
    Ui::SimpleQtClass   ui;
    QDockWidget *       m_dockInfo;
    InfoDlg *           m_dlgInfo;
    QGraphicsPixmapItem *m_viewPixmap[3];

	vector<AP_HANDLE>   m_hApBase;
	CTripleBuffer       m_TripleBuffer[3];
	CCameraThread *     m_CameraThread[3];
	CDisplayThread *    m_DisplayThread[3];

	CRecordThread *		m_RecordThread[3];

    bool                 m_bPlaying;
	bool					m_bRecording;
    ap_u32              m_nWidth;
    ap_u32              m_nHeight;
	int					cam_amount;
	int					camID;
};

#endif // SIMPLEQT_H
