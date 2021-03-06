/*     _________  ___
 _____ \_   /\  \/  / Qt/GLVideoOutputView.hpp
|  |  |_/  /__>    <  Copyright © 2014-2015 Manuel Sainz de Baranda y Goñi.
|   ____________/\__\ Released under the GNU General Public License v3.
|_*/

#ifndef __mZX_Qt_GLVideoOutputView_HPP
#define __mZX_Qt_GLVideoOutputView_HPP

#include <QGLWidget>
#include <QTimer>
#include "GLVideoOutput.hpp"
#include <Z/classes/base/Value2D.hpp>

class GLVideoOutputView : public QGLWidget {Q_OBJECT
	private:
	QTimer*	       timer;
	GLVideoOutput* videoOutput;
	bool	       active;

	public:
	explicit GLVideoOutputView(QWidget *parent = 0);
	~GLVideoOutputView();
	void initializeGL();
	void paintGL();
	void resizeGL(int width, int height);
	int heightForWidth(int width) const;
	static void drawActiveViews();
	Zeta::TripleBuffer *buffer() {return &videoOutput->buffer;}
	Zeta::Value2D<Zeta::Real> contentSize();
	void setContentSize(Zeta::Value2D<Zeta::Real> content_size);
	void setScaling(ZKey(SCALING) scaling);
	void setResolutionAndFormat(Zeta::Value2D<Zeta::Size> resolution, Zeta::UInt format);
	void start();
	void stop();
	void blank();
	void setLinearInterpolation(bool enabled);
};

#endif // __mZX_Qt_GLVideoOutputView_HPP
