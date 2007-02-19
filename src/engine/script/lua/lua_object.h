/***************************************************************************
 *   Copyright (C) 2005-2006 by the FIFE Team                              *
 *   fife-public@lists.sourceforge.net                                     *
 *   This file is part of FIFE.                                            *
 *                                                                         *
 *   FIFE is free software; you can redistribute it and/or modify          *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA              *
 ***************************************************************************/

#ifndef LUASCRIPT_OBJECT_H
#define LUASCRIPT_OBJECT_H

// Standard C++ library includes

// 3rd party library includes
extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}

// FIFE includes
// from the example at: http://lua-users.org/wiki/CppObjectBinding
#include "lunar.h"

namespace FIFE {

	namespace map {
		class ObjectInfo;
	}

	class Object_LuaScript {
		public:
			static const char className[];
			static Lunar<Object_LuaScript>::RegType methods[];

			Object_LuaScript(map::ObjectInfo *obj);
			~Object_LuaScript();

		private:
			map::ObjectInfo *m_object;
	};

}
#endif
/* vim: set noexpandtab: set shiftwidth=2: set tabstop=2: */
