/*
 *  Copyright (C) 1997-2013 JDERobot Developers Team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, see <http://www.gnu.org/licenses/>.
 *
 *  Authors : Borja Menéndez <borjamonserrano@gmail.com>
 *
 */

#ifndef DISPLAYER_H
#define DISPLAYER_H

#include <iostream>
//#include <colorspaces/colorspacesmm.h>

#include "control.h"
#include "naooperator.h"
#include "sensors.h"

void* thr_display ( void* obj );

class Displayer {
public:
    // Constructor
    Displayer ( Control* control, NaoOperator* naooperator );
    
    // Destructor
    virtual ~Displayer ();
    
    // Another functions
    void init ();
    
    Control* control;
    NaoOperator* naooperator;
    
private:
    
}; // Class Displayer

#endif
