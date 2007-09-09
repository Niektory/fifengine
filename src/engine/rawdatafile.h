/***************************************************************************
 *   Copyright (C) 2005-2006 by the FIFE Team                              *
 *   fife-public@lists.sourceforge.net                                     *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
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

#ifndef FIFERAWDATAFILE_H
#define FIFERAWDATAFILE_H

#include <string>
#include <fstream>
#include "rawdatasource.h"

namespace FIFE {

	class RawDataFile : public RawDataSource {

		public:
			RawDataFile(const std::string& file);
			virtual ~RawDataFile();

			virtual unsigned int getSize() const;
			virtual void readInto(uint8_t* buffer, unsigned int start, unsigned int length);

		private:
			std::string m_file;
			std::ifstream m_stream;

			unsigned int m_filesize;

	};

}

#endif