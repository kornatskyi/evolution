# evolution

Initial requirements:

- Some constrained area for creatures to move in
- A creature has a simple neural network that has inputs and outputs
- Inputs: sensory information like smell
- Middle layer: just makes creatures smarter
- Outputs:

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
Be able to visualize simulation data
