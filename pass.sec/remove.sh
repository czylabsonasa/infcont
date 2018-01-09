# ad-hoc script, remove all .bin files
find . -type f -name '*.bin' -print0 |
while IFS= read -r -d '' file; do
   nev=$(printf '%s\n' "$file")
   rm "${nev}"
done
