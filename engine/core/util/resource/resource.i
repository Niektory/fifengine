/***************************************************************************
 *   Copyright (C) 2005-2008 by the FIFE team                              *
 *   http://www.fifengine.de                                               *
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
%module fife

%{
#include "util/resource/resource.h"
#include "util/resource/resource_location.h"
#include "util/resource/pool.h"
%}

namespace FIFE {

	class ResourceLocation {
	public:
		virtual ~ResourceLocation() {};
		const std::string& getFilename() const;
		virtual bool operator ==(const ResourceLocation& loc) const;
		virtual bool operator <(const ResourceLocation& loc) const;
		virtual ResourceLocation* clone() const;

	private:
		ResourceLocation(const std::string& filename);
	};


	class IReferenceCounted {
		virtual ~IReferenceCounted();
		virtual void addRef() = 0;
		virtual void decRef() = 0;
		virtual unsigned int getRefCount() = 0;
	};

	class IResource: public IReferenceCounted {
	public:
		virtual ~IResource() {};
		virtual const ResourceLocation& getResourceLocation() = 0;
		virtual const std::string& getResourceFile() = 0;
		virtual void setResourceLocation(const ResourceLocation& location) = 0;
		virtual void setResourceFile(const std::string& filename) = 0;
	};

	%warnfilter(473) ResourceLoader; // filter out "returning a pointer or reference in a director method is not recommended"
	class ResourceLoader {
	public:
		virtual ~ResourceLoader() { };
		virtual IResource* loadResource(const ResourceLocation& location) = 0;
	};

	class ResourceSaver {
	public:
		virtual ~ResourceSaver() { };
		virtual void save(const ResourceLocation& location, IResource* resource) = 0;
		virtual void save(const std::string& filename, IResource* resource) { save(ResourceLocation(filename), resource); }
	};
	

	enum { RES_LOADED = 0x01, RES_NON_LOADED  = 0x02};

	class Pool {
	public:
		static const int INVALID_ID = -1;
		virtual ~Pool();
		virtual int addResourceFromFile(const std::string& filename);
		virtual int getResourceCount(int status);
		virtual void addResourceLoader(ResourceLoader* loader);
	private:
		Pool();
	};	
}
