# ad-hoc script
find . -type f -name '*.cc' -print0 |
while IFS= read -r -d '' file; do
    nev=$(printf '%s\n' "$file")
#    echo "${nev}"
   cat "${nev}" | ~/.config/hide/hide ~/.config/hide/uj > "${nev}".sec
   rm "${nev}"
done
