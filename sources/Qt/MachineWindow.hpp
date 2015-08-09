/*	_________  ___
  _____ \_   /\  \/  /	Qt/MachineWindow.hpp
 |  |  |_/  /__>    <	Copyright © 2014-2015 Manuel Sainz de Baranda y Goñi.
 |   ____________/\__\	Released under the terms of the GNU General Public License v3.
 |_*/

#ifndef __NEStalin_Qt_MachineWindow_HPP
#define __NEStalin_Qt_MachineWindow_HPP

#include <QMainWindow>
#include <QFrame>
#include <QTimer>

namespace C {
#	include <Q/types/buffering.h>
#	include "Machine.h"
}

namespace Ui {class MachineWindow;}

class MachineWindow : public QMainWindow {Q_OBJECT
	public:
	explicit MachineWindow(QWidget *parent = 0);
	~MachineWindow();
	void emulateMachine();

	private:
	Ui::MachineWindow* ui;
	C::Machine	  machine;
	void*		  memory;
	pthread_t	  thread;
	C::QRingBuffer	  audioOutputBuffer;
	C::QTripleBuffer* keyboardBuffer;
	C::Q64Bit*	  keyboard;
	C::Q64Bit	  keyboardState;
	QFrame*		  fullScreenMenuFrame;
	volatile bool	  mustStop;

	struct {bool running :1;
	} flags;

	void runMachine();
	void stopMachine();
	double currentZoom();
	void setZoom(double);

	protected:
	void keyPressEvent	   (QKeyEvent*);
	void keyReleaseEvent	   (QKeyEvent*);
	void mouseDoubleClickEvent (QMouseEvent*);
	void resizeEvent	   (QResizeEvent *);

	private slots:
	void aboutDialogClosed();
	void on_actionFileNewWindow_triggered();
	void on_actionFileOpen_triggered();
	void on_actionFileQuit_triggered();
	void on_actionMachinePower_toggled(bool);
	void on_actionMachinePause_toggled(bool);
	void on_actionMachineReset_triggered();
	void on_actionViewFullScreen_toggled(bool);
	void on_actionViewZoomIn_triggered();
	void on_actionViewZoomOut_triggered();
	void on_actionView1x_triggered();
	void on_actionView2x_triggered();
	void on_actionView3x_triggered();
	void on_actionHelpAbout_triggered();
};

#endif // __NEStalin_Qt_MachineWindow_HPP