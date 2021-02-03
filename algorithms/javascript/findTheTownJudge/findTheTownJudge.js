/**
 * @param {number} N
 * @param {number[][]} trust
 * @return {number}
 */
var findJudge = function(N, trust) {
    var cont =0;

    for(var j=1; j <= N ; j++){

        for(var i=0;i < trust.length;i++){
          if(j==trust[i][1] && trust[i][0]!=j)cont++;
            else if(trust[i][0]==j  && trust[i][1]!=j)cont--;
        }
        if(cont == N-1)return j; 
        cont=0;
    }
    return -1;    
};