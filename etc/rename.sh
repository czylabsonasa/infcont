#ad-hoc rename script
for nev in *;
do
   ujnev="${nev/uva/}"
   ujnev="${ujnev/-}"
   ujnev="${ujnev/" "/}"
   ujnev="${ujnev/"  "/" "}"

#   ujnev="${ujnev/[ ]}"
#   echo ${nev}
#   echo "vs"
   echo "${ujnev}"
   mv "${nev}" "${ujnev}"
done
