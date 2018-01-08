# hasznalat:
# sh script.sh gen progA progB ism
GEN=${1}
PA=${2}
PB=${3}
ISM=${4}
IN="IN"
CNT=0
while :
do
	./"${GEN}"
	./"${PA}" < ${IN} > oA
	./"${PB}" < ${IN} > oB
	diff oA oB
	if [ $? -eq 1 ] ;
	then
		echo ${PA}" "${PB}
		echo "hiba"
		break ;
	fi
	CNT=$(( $CNT+ 1 ))
	echo $CNT	
	if [ $CNT -ge ${ISM} ] ;
	then
		break 
	fi
done
