# hasznalat:
# sh script.sh prog_ref n ism prog
IN="IN"
CNT=0
P1=on2
P2=runme
while :
do
   ./tgen.bin
   ./${P1} < ${IN} > o1
   ./${P2} < ${IN} > o2
   echo ${P1}" "${P2}
   diff o1 o2
   if [ $? -eq 1 ] ;
   then
      echo "hiba"
      break ;
   fi
   CNT=$(( $CNT+ 1 ))
   echo $CNT
   if [ $CNT -ge ${1} ] ;
   then
      break
   fi
done
