// ==========================
// Libraries
// ==========================
#pragma once

#include "BasicActors.h"
#include <iostream>
#include <iomanip>

// ==========================
// Start of Namespace
// ==========================
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
		Box* box2;
		Box* box3;
		Box* box4;
		Box* box5;
		Box* box6;
		Box* box7;
		Sphere* sphere;

	public:
		//Custom scene initialisation
		virtual void CustomInit() 
		{
			GetMaterial()->setDynamicFriction(.2f);

			// Initialise and add the actors to the scene.
			plane = new Plane();
			Add(plane);

			box = new Box(PxTransform(PxVec3(1.5f,3.f,-10.f)));		// PxTransform, sets the inital height of the box.
			Add(box);

			box2 = new Box(PxTransform(PxVec3(0.f, 0.5f, 0.f)));
			Add(box2);

			box3 = new Box(PxTransform(PxVec3(1.f, 0.5f, 0.f)));
			Add(box3);

			box4 = new Box(PxTransform(PxVec3(2.f, 0.5f, 0.f)));
			Add(box4);
			
			box5 = new Box(PxTransform(PxVec3(0.5f, 1.5f, 0.f)));
			Add(box5);

			box6 = new Box(PxTransform(PxVec3(1.5f, 1.5f, 0.f)));
			Add(box6);

			box7 = new Box(PxTransform(PxVec3(1.f, 2.5f, 0.f)));
			Add(box7);

			sphere = new Sphere(PxTransform(PxVec3(1.5f,0.5f,-10.f)));
			Add(sphere);
		}

		// =======================
		// Custom update function
		// =======================
		virtual void CustomUpdate() 
		{
			//get position and velocity of the px_actor
			
			//note that the Get() function returns PxActor* only and therefore
			//to be able to access methods from the inherited classess (e.g. PxRigidDynamic)
			//we need to convert the pointer from PxActor* to PxRigidDynamic*
			
			PxRigidDynamic* px_actor = (PxRigidDynamic*)box->Get();
			PxVec3 position = px_actor->getGlobalPose().p;
			PxVec3 velocity = px_actor->getLinearVelocity();
			float mass = px_actor->getMass();;

			PxRigidDynamic* px_actorS = (PxRigidDynamic*)sphere->Get();
			
			
			// At the start of the loop display the mass of the object
			if (counter == 0) {
				cout << "The mass of the object is: " << mass << "kg/m^3" << endl;
				// Add a force to the object at the start of the simulation
				//px_actor->addForce(PxVec3(0.f, 0.f, 1000.f));
				px_actorS->addForce(PxVec3(0.f, 0.f, 10500.f));

				// Sets the Dynamic actor (box that can move) to a kinematic (which doesn't react to forces).
				//px_actor->setRigidBodyFlag(PxRigidBodyFlag::eKINEMATIC, true);
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

			// Change the velocity of the box if it has moved 10 meters away from its initial position.
			if (position.x + position.y + position.z >= 10) {
				//px_actor->setLinearVelocity(PxVec3(0.f, 0.f, 0.f));
			}

			// Check to see when the object isSleeping
			if (px_actor->isSleeping()) {
				//cout << "The object is now asleep" << endl;
			}

		}
	};
}
