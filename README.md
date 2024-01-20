Huffman coding is based on the idea that some letters appear a lot more than other letters so what if we make codes for each letter in which a letter's code size depends on how much it has occured in the text.

the more it appears , the smaller the code for the letter becomes.

if you dont know , read huffman coding's wikipedia page or an indian guy's yt video.
so when we apply huffman encoding to a text , we store codes and compressed code.
what if we try to compress the compressed code even more? apply huffman again?
to some extent it works....

how I applied huffman again?:
     make 8 bit pairs of compressed text , convert them to normal text , then apply the algorithm again.
