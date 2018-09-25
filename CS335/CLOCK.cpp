/***********************************************************************        
* Program:                                                                      
*    Lab PageReplacement                                                        
*    Brother Jones, CS 345                                                      
* Author:                                                                       
*    Donovan Gregory                                                            
* Summary:                                                                      
*    Doing a clock or second chance algorithm on a page table. It's             
*    funny how if you just do this one as FIFO it will be correct over 50%      
*    of the time.                                                               
************************************************************************/
/*                                                                              
**====================================================================**        
* The following will be filled out for the second submission.  For the          
* first submission, you may leave it in your code or delete it.                 
*                                                                               
* The second submission should be submitted to labPageReplacementT2.            
* (Which means the third line of the headers in CLOCK.cpp, FIFO.cpp and         
* LRU.cpp files need to have a "T2" added onto the name of the lab.)            
**====================================================================**        
*                                                                               
* Changes made to my code for the re-submission:                                
*   (examples:)                                                                 
*   -I added comments such that they would help me remember what I did to       
*    write this program in another six months.                                  
*   -Fixed an error, ...                                                        
*   - ...                                                                       
*                                                                               
************************************************************************/

#include "vmalgorithm.h"

/**************************************************************************     
 * Function:                                                                    
 *    void CLOCK::execute() - Executes the CLOCK page replacement algorithm     
 * Inherited Variables and Methods:                                             
 *    int NUM_FRAMES: How many frames there are in 'memory'. (eg. 4)            
 *    int frames[NUM_FRAMES]: The array that contains the pages resident        
 *          in memory.  Use this array for the pages in memory.                 
 *          See Also: NUM_FRAMES                                                
 *    int hit(int page): Function that scans the 'frames[]' array, searching    
 *          for 'page'.  If 'page' is found, it will return the index of        
 *          the 'frames[]' array.  If the page is not found, the function       
 *          returns '-1'.                                                       
 *    int myPageFactory->getPage(): Returns the next page the psuedo-program    
 *          requests.  When there are no more pages to return, this function    
*          returns a -1.                                                       
 *    void display(int page, int frames[], bool fault): Function to display     
 *          the information to stdout.  The parameter 'page' is the current     
 *          page (the one returned from myPageFactory->getPage()), 'frames[]'   
 *          is the array of the current resident set, and when 'fault' is       
 *          true, the display function will indicate it to the screen.          
 *          This function must be called for every page that is accessed.       
 *************************************************************************/
void CLOCK::execute()
{
	// Keepes track of pagetable number                                          
	int marker = 0;

	// Keeps track of first four                                                 
	int firstFour = 0;

	// Keep track of faults,                                                     
	bool fault;

	// Holds the accessed page                                                   
	int page;

	  // Array of second chances                                                   
		int chance [NUM_FRAMES][2];

		for(int i = 0; i < NUM_FRAMES; i++) //Sets up the chance array with 0s       
			for(int j = 0; j < 2; j++)
				chance [i][j] = 0;

		while ( (page = myPageFactory->getPage()) != -1 )
		{
			fault = false; // assume false until we have a fault.                     

			if ( hit(page) == -1 )
			{
				fault = true;
				if(firstFour < NUM_FRAMES){ //Sets up first four, including setting    
					chance[firstFour][0] = page; // up chances                          
					chance[firstFour][1] = 1;
					frames[firstFour] = page;
					firstFour++;
					//cout << "t1 ";                                                    
				}

				else{
				 for(int i = marker; i <= NUM_FRAMES; i++){ //sets up to go through  
								if(chance[i][1] == 1 && i != NUM_FRAMES){ // the array           
									chance[i][1] = 0; //sets chance to 0                          
								}
								else if(chance[i][1] == 0 && i != NUM_FRAMES){
									chance[i][0] = page; // If the current itteration             
									chance[i][1] = 1; // chance is 0 and we are not               
									frames[i] = page; // at the end of the iteration then         
									marker = i+1; // we can reset the page there                  
									i = NUM_FRAMES +1;
								}

								else if(chance[0][1] == 0 && chance[1][1] == 0 &&
										  chance[2][1] == 0 && chance[3][1] == 0 &&
										  chance[0][0] != page && chance[1][0] != page
										  && chance[2][0] != page && chance[3][0] != page
										  && i == NUM_FRAMES){
									chance[0][0] = page; //This takes care of the problem when    
									chance[0][1] = 1; // all chances are out                      
									frames[0] = page;
									marker = 1;
									i = NUM_FRAMES +1;
								}
								
								else if(i == NUM_FRAMES && chance[0][0] != page &&
										  chance[1][0] != page && chance[2][0] != page &&
										  chance[3][0] != page){
									i = -1; // this resets the iteration if we get to             
								} //the end                                                      
							}
						}

					}

					for(int i = 0; i < NUM_FRAMES; i++){ //This resets the chance if a number
						if(chance[i][0] == page){ // repops up                                 
							chance[i][1] = 1;
						}
					}
					display(page, frames, fault);
				}

			}
