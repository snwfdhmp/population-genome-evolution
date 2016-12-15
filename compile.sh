export README="README.txt"
g++ main.c Gene.cpp Humain.cpp
echo "Simulation de population par reproduction génétique et brassages chromosomiques" > $README
echo "DERNIERE MAJ : $(date)" >> $README
./a.out >> $README 2>> $README
git add *
git commit -m "UPDATE"
git push origin master
echo "==============="
echo "== README.md =="
echo "==============="
cat $README
