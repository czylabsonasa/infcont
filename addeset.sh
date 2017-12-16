if [ -d work/"${1}" ];
then
    echo "problem exists. exit"
    exit 1
fi
cd work
mkdir "${1}"
cp ../skeletoneset.cc "${1}"/"${1}".cc
cd "${1}"
touch in
touch "${1}".bin #assuming the same name for binary (e.g. geany)
ln -s "${1}".bin runme
chmod +x runme
cd ../..
