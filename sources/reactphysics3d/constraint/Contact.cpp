/****************************************************************************
* Copyright (C) 2009      Daniel Chappuis                                  *
****************************************************************************
* This file is part of ReactPhysics3D.                                     *
*                                                                          *
* ReactPhysics3D is free software: you can redistribute it and/or modify   *
* it under the terms of the GNU Lesser General Public License as published *
* by the Free Software Foundation, either version 3 of the License, or     *
* (at your option) any later version.                                      *
*                                                                          *
* ReactPhysics3D is distributed in the hope that it will be useful,        *
* but WITHOUT ANY WARRANTY; without even the implied warranty of           *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the             *
* GNU Lesser General Public License for more details.                      *
*                                                                          *
* You should have received a copy of the GNU Lesser General Public License *
* along with ReactPhysics3D. If not, see <http://www.gnu.org/licenses/>.   *
***************************************************************************/

// Libraries
#include "Contact.h"
#include "../body/RigidBody.h"
#include <GL/freeglut.h>        // TODO : Remove this in the final version
#include <GL/gl.h>              // TODO : Remove this in the final version

// We want to use the ReactPhysics3D namespace
using namespace reactphysics3d;

// Constructor
Contact::Contact(Body* const body1, Body* const body2, const Vector3D& normal, double penetrationDepth, const std::vector<Vector3D>& points)
                 :Constraint(body1, body2, 2, 0, INFINITY_CONST, true), normal(normal), penetrationDepth(penetrationDepth), points(points) {
    body1Jacobian = Matrix(1, 6);
    body2Jacobian = Matrix(1, 6);
    auxJacobian = Matrix(2, 6);
}

// Destructor
Contact::~Contact() {

}

// Evaluate the constraint
// This method computes the jacobian matrices of the constraint
void Contact::evaluate() {
    RigidBody* rigidBody1 = dynamic_cast<RigidBody*>(body1);
    RigidBody* rigidBody2 = dynamic_cast<RigidBody*>(body2);

    assert(rigidBody1 != 0);
    assert(rigidBody2 != 0);

    // Compute the jacobian matrix for the body 1

}

// TODO : Delete this (Used to debug collision detection)
void Contact::draw() const {
    glColor3f(1.0, 0.0, 0.0);
    glutSolidSphere(0.5, 20, 20);
}
