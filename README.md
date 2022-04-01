# UnivSimSys

# Framework for general Simulations (in c++)
#### Entities:
  -  A dynamic number of simulation participants (**Entities**)
     - which contain a method themselves, in which they can execute their logic once per tick
     - which contain a way of receiving information from other places of the Simulation to communicate (**Events**) (and reacting to those)
     - (a way of perceiving the Entity's surrounding) (this may correspond to [Spatial](Spatial))
#### Spatial: 
  - A **spatial data structure** that allows for comparing positions and **collision testing** in a **continously chaning enviroment** (Octatrees or grid, maybe)
    - so that actions/reactions can be taken when specific things (**Events**) accour (like collision)
    - some kind of terrain information, which should not be fixed and changeable (a 3D representation of the env.)
#### Communication:
  - A **way of communicating** information (my idea was custom Events for handable Events)
  - (if possible) these Events should contain a call back of some sort (this can be accoplished by the current logic already by storing a sender ptr)