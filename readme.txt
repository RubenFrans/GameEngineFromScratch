Ruben Frans 
Class: 2DAE06E

Git Repository: 
https://github.com/RubenFrans/GameEngineFromScratch

Design desisions:

- Physics World
	- Each scene manages its own physics world to keep the physics simulation seperate.

- Box2D
	- The engine implements the Box2D library for physics, collision and triggers, this makes the engine more robust and easier to adapt for creating different kinds of games.
	- Box2D implememntations are made using simple wrapper classes
	- Box2D implementations in the engine:
		- RigidBody
		- BoxCollider
		- CircleCollider
		- Colliders can be static, dynamic, kinematic
		- Triggers
			
			Triggers use a callback function that gets called with a collision or trigger overlap with the corresponding action( Enter, Leave )


- Renderer
	- I Expanded the renderer to support drawing parts of textures, this way spritesheets can be used to save memory.

