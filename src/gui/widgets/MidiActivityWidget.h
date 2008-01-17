/*
 * Hydrogen
 * Copyright(c) 2002-2005 by Alex >Comix< Cominu [comix@users.sourceforge.net]
 *
 * http://www.hydrogen-music.org
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY, without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * $Id: MidiActivityWidget.h,v 1.10 2005/05/30 21:23:49 comix Exp $
 *
 */


#ifndef MIDI_ACTIVITY_WIDGET_H
#define MIDI_ACTIVITY_WIDGET_H

#include <string>
using std::string;

#include "config.h"
#include "qwidget.h"
#include "qpixmap.h"

#include "../EventListener.h"
#include "lib/Object.h"

class MidiActivityWidget : public QWidget, public EventListener, public Object
{
	Q_OBJECT
	public:
		MidiActivityWidget(QWidget * parent);
		~MidiActivityWidget();

		void setValue(uint newValue);
		uint getValue();

		void mousePressEvent(QMouseEvent *ev);
		void paintEvent(QPaintEvent *ev);

	public slots:
		void updateMidiActivityWidget();

	private:
		uint m_nValue;

		QPixmap m_temp;
		QPixmap m_back;
		QPixmap m_leds;

		virtual void midiActivityEvent();
};

#endif