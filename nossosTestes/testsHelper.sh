#!/usr/bin/bash
# make imageTool

# testes para image locate sub image

# image arrays

# cd nossosTestes || exit 1
# get opts
## global
original="VERYBIG_10000x10000.pgm"
while getopts ":l:cdbr" opt; do
    case $opt in
        l)
            imgs=$(ls $OPTARG/VERYBIG*)
            
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
                # \../imageTool $img "../pgm/small/bird_256x256.pgm" locate >>tables/LocateTable.txt
                \../imageTool $img "/home/andre/Desktop/UA/2023_24/1_SEMESTRE/AED/proj1/trabalho1-112974-113170/nossosTestes/VERYBIG_10000x10000.pgm" locate >>tables/LocateTable4.txt
            done
            
            exit 0
            
        ;;
        c)
            orig="/home/andre/Desktop/UA/2023_24/1_SEMESTRE/AED/proj1/trabalho1-112974-113170/nossosTestes/VERYBIG_10000x10000.pgm"
            
            X=0
            Y=0
            width=($(echo {0..10000..500}))
            
            height=($(echo {0..10000..500}))
            
            # ./imageTool someIMAGE crop X,Y,W,H save img.pgm
            for i in "${!width[@]}"; do
                X=0
                Y=0
                echo $X,$Y,${width[$i]},${height[$i]}
                # if i is not index of heigth it should be the last one
                
                \../imageTool $orig crop $X,$Y,${width[$i]},${height[$i]} save ./trashImages/VERYBIG_${i}_$((${width[$i]}))x$((${height[$i]})).pgm
                
                
                
                
                
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
        b)
            orig="./trashImages/VERYBIG_200_10000x10000.pgm"
            imgs=($(ls trashImages/VERYBIG*))
            sq=7
            # echo imgs: "${imgs[@]}"
            # squares=($(echo {0..5000..50}))
            for i in "${!imgs[@]}"; do
                echo img: ${imgs[$i]} sq: $sq
                \../imageTool ${imgs[$i]} blur $sq,$sq >>tables/BlurTable.txt # save ./trashImages/blend_${i}_$((${squares[$i]}))x$((${squares[$i]})).pgm
                # ./imageTool someIMAGE crop X,Y,W,H save img.pgm
            done
            
        ;;
        
        r)
            # Tamanho da imagem base
            base_image_size="10000x10000"
            
            # Número de imagens de teste
            num_test_images=100
            
            # Crie diretório para armazenar as imagens de teste
            mkdir -p test_images
            orig="./trashImages/VERYBIG_200_10000x10000.pgm"
            
            
            for ((i = 1; i <= num_test_images; i++)); do
                # Gere posições e tamanhos aleatórios
                X=$(($RANDOM % 9701))  # x variando de 0 a 9700 para garantir que a largura + x seja no máximo 10000
                Y=$(($RANDOM % 9701))  # y variando de 0 a 9700 para garantir que a altura + y seja no máximo 10000
                width1=$(($RANDOM % (10000 - $X) + 1))  # Largura aleatória entre 1 e (10000 - x) pixels
                height1=$(($RANDOM % (10000 - $Y) + 1)) # Altura aleatória entre 1 e (10000 - y) pixels
                echo $X,$Y,$width1,$height1
                
                
                \../imageTool $orig crop $X,$Y,$width1,$height1 save ./test_images/VERYBIG_${i}_"$width1"x"$height1".pgm
                
            done
            # orig="../pgm/small/bird_256x256.pgm"
            # mkdir -p all500x500
            # w=246
            # h=246
            # i=0
            # for x in {0..10};do
            #     for y in {0..10}; do
            #         \../imageTool $orig crop $x,$y,$w,$h save ./all500x500/VERYBIG_${i}_"$w"x"$h"_"$x"_"$y"_.pgm
            #         i=$((i+1))
            #     done
            # done
            
            
            
        ;;
        *)
            
            echo "Option -$OPTARG requires an argument." >&2
            exit 1
        ;;
    esac
done
