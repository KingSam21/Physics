#pragma once

#include "BasicActors.h"
#include <iostream>
#include <iomanip>

namespace PhysicsEngine
{
	using namespace std;

	//Create a global counter for measuring the number of simulation steps
	int counter = 0;

	///A custom scene class
	class MyScene : public Scene
	{
		// Create instances of objects
		Plane* plane;
		Box* box;

	public:
		//Custom scene initialisation
		virtual void CustomInit() 
		{
			GetMaterial()->setDynamicFriction(.2f);

			// Initialise and add the actors to the scene.
			plane = new Plane();
			Add(plane);

			box = new Box(PxTransform(PxVec3(0.f,0.5f,0.f)));
			Add(box);
		}



		// =====================
		//Custom udpate function
		// =====================
		virtual void CustomUpdate() 
		{
			//get position and velocity of the px_actor
			
			//note that the Get() function returns PxActor* only and therefore
			//to be able to access methods from the inherited classess (e.g. PxRigidDynamic)
			//we need to convert the pointer from PxActor* to PxRigidDynamic*
			
			PxRigidDynamic* px_actor = (PxRigidDynamic*)box->Get();
			PxVec3 position = px_actor->getGlobalPose().p;
			PxVec3 velocity = px_actor->getLinearVelocity();
			float mass = px_actor->getMass();
			
			// At the start of the loop display the mass of the object
			if (counter == 0) {
				cout << "The mass of the object is: " << mass << "kg/m^3" << endl;
				// Add a force to the object
				px_actor->addForce(PxVec3(100.f, 0.f, 0.f));
			}

			//'visualise' position and velocity of the box
			cout << setiosflags(ios::fixed) << setprecision(2) << "x=" << position.x << 
				", y=" << position.y << ", z=" << position.z << ",  ";
			cout << setiosflags(ios::fixed) << setprecision(2) << "vx=" << velocity.x << 
				", vy=" << velocity.y << ", vz=" << velocity.z << endl;
			
			//Iterate and then Display the Global counter
			counter++;
			cout << "Current Simulation Step: " << counter << endl;

			// Change the position of the box, if the simulation steps have reached 10
			if (counter == 10) {
				//px_actor->setGlobalPose(PxTransform(PxVec3(10.f,position.y, 0.f)));
			}

		}
	};
}
