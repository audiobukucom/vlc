/*****************************************************************************
 * theme.hpp
 *****************************************************************************
 * Copyright (C) 2003 VideoLAN
 * $Id: theme.hpp,v 1.2 2004/01/25 23:04:06 asmax Exp $
 *
 * Authors: Cyril Deguet     <asmax@via.ecp.fr>
 *          Olivier Teuli�re <ipkiss@via.ecp.fr>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111, USA.
 *****************************************************************************/

#ifndef THEME_HPP
#define THEME_HPP

#include "../src/generic_bitmap.hpp"
#include "../src/generic_font.hpp"
#include "../src/generic_window.hpp"
#include "../src/generic_layout.hpp"
#include "../src/window_manager.hpp"
#include "../commands/cmd_generic.hpp"
#include "../utils/variable.hpp"
#include "../controls/ctrl_generic.hpp"
#include <string>
#include <list>
#include <map>


/// Class storing the data of the current theme
class Theme: public SkinObject
{
    public:
        Theme( intf_thread_t *pIntf ): SkinObject( pIntf ),
            m_windowManager( getIntf() ) {}
        virtual ~Theme();

        void loadConfig();
        void saveConfig();

        GenericBitmap *getBitmapById( const string &id );
        GenericFont *getFontById( const string &id );
        GenericWindow *getWindowById( const string &id );
        GenericLayout *getLayoutById( const string &id );
        CtrlGeneric *getControlById( const string &id );

        WindowManager &getWindowManager() { return m_windowManager; }

        // XXX: It would be nicer to put everything private, and have the
        // builder and interpreter classes as friends of this one
//     private:
        /// Store the bitmaps by ID
        map<string, GenericBitmapPtr> m_bitmaps;
        /// Store the fonts by ID
        map<string, GenericFontPtr> m_fonts;
        /// Store the windows by ID
        map<string, GenericWindowPtr> m_windows;
        /// Store the layouts by ID
        map<string, GenericLayoutPtr> m_layouts;
        /// Store the controls by ID
        map<string, CtrlGenericPtr> m_controls;
        /// Store the commands
        list<CmdGenericPtr> m_commands;
        /// Store the variables
        list<VariablePtr> m_vars;

    private:
        WindowManager m_windowManager;
};


#endif
