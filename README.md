# Evolution 🧬

## Requirements:
1. Some constrained area for creatures to move in
2. Creatures:
   1. Creatures can move around inside the area boundaries
   2. Creatures have simple neural networks
      1. Neural network:
         1. Inputs: sensory information like smell, (or in the future it can be vision(proximity to other creatures or objects)) 
         2. Outputs: parameters for creature's behavior such as movement direction (also in the future it can expand any other behaviors)
         3. Middle layer: just makes creatures smarter
   3. Creatures have senses, the information from senses is used as inputs for the creature's brain neural net (brain).
   4. Creatures behavior is governed by its neural network outputs.
3. Collision detection
   1. Prevent creatures from going through walls
   2. Maybe prevent creatures from going through each other. Make it so creatures can detect collision with one another and collision with food or other object in the simulation.


## Implementation
Entities:
Food:
properties:
position

Creature:
properties:
position
genome
alive
foundFood

functions:
gatherInformation(smell)
move()

Post simulation:
Genome visualizer
Generate simulation history
Be able to visualize simulation 


