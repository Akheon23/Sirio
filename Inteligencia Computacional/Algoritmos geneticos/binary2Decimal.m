%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%convert a binary vector in a integer
% Autor: Alexander Gomez Villa
% email: alviurlex@gmail.com
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Result b is a row vector of size 111 the firts number is the sign,
% from 2 to 56 it's the integer part and from 57 to 111 it's the frac-
% tional part.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function d= binary2Decimal(x)

    %Integer part
    
    integerVect=x(1,2:53);%extrac integer part from x
    combinedStr=int2str(integerVect(1));%string for integer part
    for i=2:size(integerVect,2)
        combinedStr = strcat(combinedStr,int2str(integerVect(i)));%transform integer into string
    end

    integer=bin2dec(combinedStr);%convert binary integer to decimal integer
    
    %Fractional part
    
    fractionalVect=x(1,54:105);%extrac fractional part from x
    fracitonal=0;%accumulate 
    
    for i=1:size(fractionalVect,2)
        
        fracitonal= fracitonal + (fractionalVect(i))*2^(-(i));%sums each binary contribution
        
    end    

    d=integer + fracitonal;%answer
    
    if(x(1,1)<1) d= d* (-1); end

end