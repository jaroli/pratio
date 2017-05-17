Calculates the participation ratio which is a measure of the wavefunction localization.
This is usefull when studying amorphous semiconductors, where states close to the valence and
conduction band edge are localized.
The program is a post-processing tool that reads output from the [Vienna Ab initio Simulation Package](http://vasp.at).

# Installation
Just compile with `g++ -o pratio pratio.cc` and put the executable in your `bin` folder.

# Usage
One first has to perform a VASP calculation that will generate the PROCAR file.
This is achieved by including RWIGS in your INCAR file. More details can be found
in the [VASP manual](http://cms.mpi.univie.ac.at/vasp/vasp/PROCAR_file.html).

The program will read the PROCAR and calculate the participation ratio based on
the definition by R.J. Bell and P. Dean in Localization of phonons in vitreous
silica and related glasses in R.W. Douglas (ed.) Amorphous materials, p.443-451,
(1972). The output file is `pratio.out`.

# Example
![amorphous silicon](./example/pratio.png)

<img src="./example/pratio.png" width="48">
