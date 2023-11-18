#!/usr/bin/bash
# make imageTool

# testes para image locate sub image

# image arrays

# cd nossosTestes || exit 1
# get opts
## global
original="VERYBIG_10000x10000.pgm"
while getopts ":lcd" opt; do
    case $opt in
        l)
            imgs=$(ls trashImages/VERYBIG*)
            
            #find the original image
            
            # echo "" >tables/LocateTable.txt # guarantee that the file is empty this makes an empty line
            
            for img in $imgs; do
                if [ "$img" == "$original" ]; then
                    imgOriginal=$img
                fi
                # ./imageTool subImage Image locate
                # \../imageTool
            done
            
            for img in $imgs; do
                # ./imageTool subImage Image locate
                \../imageTool $img "trashImages/VERYBIG_200_10000x10000.pgm" locate >>tables/LocateTable.txt
            done
            
            exit 0
            
        ;;
        c)
            X=0
            Y=0
            width=($(echo {0..10000..50}))
            
            height=($(echo {0..10000..50}))
            
            # ./imageTool someIMAGE crop X,Y,W,H save img.pgm
            for i in "${!width[@]}"; do
                # if i is not index of heigth it should be the last one
                
                \../imageTool $original crop $X,$Y,${width[$i]},${height[$i]} save ./trashImages/VERYBIG_${i}_$((${width[$i]}))x$((${height[$i]})).pgm
                
                echo "${width[$i]} ${height[$i]}"
            done
            
        ;;
        d)
            
            
            # Define the target fraction
            target_numerator=15092
            target_denominator=10002
            
            # Find the greatest common divisor (GCD) of numerator and denominator
            gcd() {
                if [ $2 -eq 0 ]; then
                    echo $1
                else
                    gcd $2 $(( $1 % $2 ))
                fi
            }
            
            # Iterate through possible values of x
            for ((x=1; x<=target_numerator; x++)); do
                # Calculate y based on the target fraction
                y=$((target_denominator * x / target_numerator))
                
                # Check if x/y equals the target fraction
                if [ $((target_denominator * x)) -eq $((target_numerator * y)) ]; then
                    echo "x = $x, y = $y"
                fi
            done
            
        ;;
        *)
            
            echo "Option -$OPTARG requires an argument." >&2
            exit 1
        ;;
    esac
done
