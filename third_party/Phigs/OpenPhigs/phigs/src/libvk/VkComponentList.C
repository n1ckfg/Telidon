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

#include <Vk/VkComponentList.h>

///////////////////////////////////////////////////////////////////////////////
// VkComponentList
//
// DESCR:       Initialize component list
// RETURNS:     N/A
//
VkComponentList::VkComponentList()
{
    _numComponents = 0;
    _components = NULL;
}

///////////////////////////////////////////////////////////////////////////////
// ~VkComponentList
//
// DESCR:       Destroy component list
// RETURNS:     N/A
VkComponentList::~VkComponentList()
{
    _numComponents = 0;
    XtFree((char *) _components);
}

///////////////////////////////////////////////////////////////////////////////
// add
//
// DESCR:       Add component to component list
// RETURNS:     N/A
//
void VkComponentList::add(
    VkComponent *component
    )
{
    // Allocate the array to be one element larger than current size
    _components = (VkComponent **) XtRealloc((char *) _components,
        sizeof(VkComponent *) * (_numComponents + 1));

    // Add the new element to the end of the list
    _components[_numComponents++] = component;
}

///////////////////////////////////////////////////////////////////////////////
// remove
//
// DESCR:       Remove component from component list
// RETURNS:     N/A
//
void VkComponentList::remove(
    VkComponent *component
    )
{
    // Find the item in the list
    for (int i = 0; i < _numComponents; i++) {

        if (_components[i] == component) {

            // Decrease the size of the list,
            // and move remaining items in the list up one space
            _numComponents--;

            for (int j = 0; j < _numComponents; j++) {
                _components[j] = _components[j + 1];
            }

            // Reduce the size of the list
            _components = (VkComponent **) XtRealloc((char *) _components,
                sizeof(VkComponent *) * _numComponents);

            return;
        }

    }
}

///////////////////////////////////////////////////////////////////////////////
// operator[]
//
// DESCR:       Get pointer to component at index in array
// RETURNS:     Pointer to component
//
VkComponent* VkComponentList::operator[](
    int index
    ) const
{
    return _components[index];
}

