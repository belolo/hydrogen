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
 * $Id: HydrogenApp.h,v 1.11 2005/05/09 18:10:54 comix Exp $
 *
 */
#ifndef HYDROGEN_APP_H
#define HYDROGEN_APP_H

#include <iostream>
#include <qstatusbar.h>
#include <qfiledialog.h>
#include <qapplication.h>
#include <qmessagebox.h>
#include <qobject.h>

#include "config.h"

#include "lib/Object.h"
#include "lib/Song.h"

#include "EventListener.h"
#include <vector>

class SongEditorPanel;
class MainForm;
class PlayerControl;
class PatternEditorPanel;
class InstrumentEditor;
class SongEditor;
class Mixer;
class AudioEngineInfoForm;
class SimpleHTMLBrowser;
class DrumkitManager;
class LadspaFXProperties;
class LadspaFXInfo;
class LadspaFXGroup;

class HydrogenApp : public QObject, public Object
{
	Q_OBJECT
	public:
		HydrogenApp( MainForm* pMainForm, Song *pFirstSong );

		/// Returns the instance of HydrogenApp class
		static HydrogenApp* getInstance();

		virtual ~HydrogenApp();

		void setSong(Song* pSong);
		Song *getSong();

		void showPreferencesDialog();
		void showMixer(bool bShow);
		void showAudioEngineInfoForm();

		Mixer* getMixer() {	return m_pMixer;	}
		MainForm* getMainForm() {	return m_pMainForm;	}
		SongEditorPanel* getSongEditorPanel() {	return m_pSongEditorPanel;	}
		AudioEngineInfoForm* getAudioEngineInfoForm() {	return m_pAudioEngineInfoForm;	}
		SimpleHTMLBrowser* getHelpBrowser() {	return m_pHelpBrowser;	}
		DrumkitManager* getDrumkitManager() {	return m_pDrumkitManager;	}
		PatternEditorPanel* getPatternEditorPanel() {	return m_pPatternEditorPanel;	}
		InstrumentEditor* getInstrumentEditor() {	return m_pInstrumentEditor;	}
		PlayerControl* getPlayerControl() {	return m_pPlayerControl;	}

		void setStatusBarMessage(QString msg, int msec = 0);

#ifdef LADSPA_SUPPORT
		LadspaFXProperties* getLadspaFXProperties(uint nFX) {	return m_pLadspaFXProperties[nFX];	}
		std::vector<LadspaFXInfo*> getPluginList() {	return m_pluginList;	}
		LadspaFXGroup* getFXRootGroup() { return m_pFXRootGroup;	}
#endif
		void addEventListener( EventListener* pListener );
		void removeEventListener( EventListener* pListener );

	public slots:
		void onEventQueueTimer();

	private:
		static HydrogenApp *m_pInstance;	///< HydrogenApp instance

		QStatusBar *m_pStatusBar;
		MainForm *m_pMainForm;
		Mixer *m_pMixer;
		PatternEditorPanel* m_pPatternEditorPanel;
		AudioEngineInfoForm *m_pAudioEngineInfoForm;
		SongEditorPanel *m_pSongEditorPanel;
		SimpleHTMLBrowser *m_pHelpBrowser;
		SimpleHTMLBrowser *m_pFirstTimeInfo;
		DrumkitManager *m_pDrumkitManager;
#ifdef LADSPA_SUPPORT
		std::vector<LadspaFXInfo*> m_pluginList;
		LadspaFXProperties *m_pLadspaFXProperties[MAX_FX];
		LadspaFXGroup *m_pFXRootGroup;
#endif
		InstrumentEditor* m_pInstrumentEditor;
		PlayerControl *m_pPlayerControl;

		QTimer *m_pEventQueueTimer;
		std::vector<EventListener*> m_eventListeners;

		// implement EngineListener interface
		void engineError(uint nErrorCode);

		void setupTopLevelInterface();
		void setupMDIInterface();
		void setupSinglePanedInterface();
		void showInfoSplash();
};


#endif