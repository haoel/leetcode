/***************************************************************************************************** 
 *
 * We distribute some number of candies, to a row of n = num_people people in the
 * following way:
 * 
 * We then give 1 candy to the first person, 2 candies to the second person, and so on until 
 * we give n candies to the last person.
 * 
 * Then, we go back to the start of the row, giving n + 1 candies to the first person, n +
 * 2 candies to the second person, and so on until we give 2 * n candies to the last
 * person.
 * 
 * This process repeats (with us giving one more candy each time, and moving to the start of
 * the row after we reach the end) until we run out of candies.  The last person will receive all
 * of our remaining candies (not necessarily one more than the previous gift).
 * 
 * Return an array (of length num_people and sum candies) that represents the final
 * distribution of candies.
 * 
 * 
 * Example 1:
 * 
 * Input: candies = 7, num_people = 4
 * Output: [1,2,3,1]
 * Explanation:
 * On the first turn, ans[0] += 1, and the array is [1,0,0,0].
 * On the second turn, ans[1] += 2, and the array is [1,2,0,0].
 * On the third turn, ans[2] += 3, and the array is [1,2,3,0].
 * On the fourth turn, ans[3] += 1 (because there is only one candy 
 * left), and the final array is [1,2,3,1].
 * 
 * Example 2:
 *
 * Input: candies = 10, num_people = 3
 * Output: [5,2,3]
 * Explanation: 
 * On the first turn, ans[0] += 1, and the array is [1,0,0].
 * On the second turn, ans[1] += 2, and the array is [1,2,0].
 * On the third turn, ans[2] += 3, and the array is [1,2,3].
 * On the fourth turn, ans[0] += 4, and the final array is [5,2,3].
 * 
 * 
 * Constraints:
 * 
 *  1 <= candies <= 10^9
 *  1 <= num_people <= 1000
 * 
 * Explanation of the solution:
 * 
 * 1. While we have given less candies than the ones we had at the beginning (while(total < candies){...})
 * 
 * 2. Use count % num_people == 0 to determine the current index of the people.
 ******************************************************************************************************/

class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int[] res = new int[num_people];        //Initialize the array of people
        int toGiveCandie = 1, count = 0, total = 0;    
        while(total < candies){                 //While the total candies given is fewer than the candies we have...
            if(count % num_people == 0){        //This is to 'reset' de counter to 0 when we reach the last person.
                count = 0;
            }
            if(total + toGiveCandie <= candies){  
                //If the number of candies we have already given plus the candies we are 
                // going to give are less or equal than the total candies...
                res[count] += toGiveCandie;     //We add the candies to the array (give the candie to the person)
                total += toGiveCandie;          //We update the candies we have given
                toGiveCandie++;                 //To the next person we will give one more candie
            }else{
                //If we don't have the enough candies, we just give the candies left
                res[count] += candies-total;    
                total += candies-total;
                toGiveCandie++;
            }
            count++;
        }
        return res;                            //We return the filled array
    }
}
