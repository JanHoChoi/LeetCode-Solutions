class Solution
{
  public:
    int countDigitOne(int n)
    {   // n>=0
        int res = 0;
        for(long factor = 1; factor <= n; factor *= 10){
		    int currentNum = (n / factor) % 10; // 当前判断的位的值
		    int highNum = (n / factor)/10; // 截去当前位及后面所有，剩下前面所有位的值
		    int lowNum = n % factor; // 当前位后面的所有位的值
		
		    switch(currentNum){
			    case 0: // 当前位是0 则为高位*factor(比如10) 如34|02 出现在十位的1有34(00~33)*10(后面的位有factor个可能)种可能性。
				    res += highNum * factor;
				    break;
			    case 1: // 比如34|12 出现在十位的1有34*factor(10) (0000~3400) + 2(3411和3412) + 1(3410)
				    res += highNum * factor + lowNum + 1; // 即 |1|xxxx个数=xxxx+1
				    break;
			    default: // 比如34|22 出现在十位的1有(34+1)*factor (00 ~ 34)
				    res += (highNum + 1) * factor;
				    break;
		    }
	    }
        return res;
    }
};