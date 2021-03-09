///////////////////////////////////////////////////////////////////////////////
//  DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS HEADER
//
//  This file is part of Open PHIGS
//  Copyright (C) 2011 - 2012 Surplus Users Ham Society
//
//  Open PHIGS is free software: you can redistribute it and/or modify
//  it under the terms of the GNU Lesser General Public License as published by
//  the Free Software Foundation, either version 2.1 of the License, or
//  (at your option) any later version.
//
//  Open PHIGS is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public License
//  along with Open PHIGS. If not, see <http://www.gnu.org/licenses/>.
///////////////////////////////////////////////////////////////////////////////

#ifndef _VkComponentList_H
#define _VkComponentList_H

#include <Vk/VkComponent.h>

class VkComponentList : public VkComponent {
public:

    ///////////////////////////////////////////////////////////////////////////
    // VkComponentList
    //
    // DESCR:       Initialize component list
    // RETURNS:     N/A
    //
    VkComponentList();

    ///////////////////////////////////////////////////////////////////////////
    // ~VkComponentList
    //
    // DESCR:       Destroy component list
    // RETURNS:     N/A
    //
    virtual ~VkComponentList();

    ///////////////////////////////////////////////////////////////////////////
    // add
    //
    // DESCR:       Add component to component list
    // RETURNS:     N/A
    //
    virtual void add(
        VkComponent *component
        );

    ///////////////////////////////////////////////////////////////////////////
    // remove
    //
    // DESCR:       Remove component from component list
    // RETURNS:     N/A
    //
    virtual void remove(
        VkComponent *component
        );

    ///////////////////////////////////////////////////////////////////////////
    // size
    //
    // DESCR:       Get number of components in component list
    // RETURNS:     N/A
    //
    int size() const { return _numComponents; }

    ///////////////////////////////////////////////////////////////////////////
    // operator[]
    //
    // DESCR:       Get pointer to component at index in array
    // RETURNS:     Pointer to component
    //
    VkComponent* operator[](
        int index
        ) const;

private:

    // Array of pointers to components
    VkComponent **_components;

    // Number of items in array of component pointers
    int _numComponents;
};

#endif

