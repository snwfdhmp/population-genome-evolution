g++ main.c Gene.cpp Humain.cpp
echo "Simulation de population par reproduction génétique et brassages chromosomiques" > README.md
echo "DERNIERE MAJ : $(date)" >> README.md
./a.out >> README.md 2>> README.md
git add *
git commit -m "UPDATE"
git push origin master
cat README.md
