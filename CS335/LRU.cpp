/***********************************************************************        
* Program:                                                                      
*    Lab PageReplacement                                                        
*    Brother Jones, CS 345                                                      
* Author:                                                                       
*    Donovan Gregory                                                            
* Summary:                                                                      
*    This will use the Least Recently Used Replacement algorithm                
*    to sort through a page table.                                              
************************************************************************/

#include "vmalgorithm.h"
#include <deque>
/**************************************************************************     
 * Function:                                                                    
 *    void LRU::execute() - Executes the LRU page replacement algorithm         
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
void LRU::execute()
{

	// Keep track of faults,                                                     
	bool fault;

	// Holds the accessed page                                                   
	int page;

	//used to distinguish the first four                                         
	int marker = 0;

	//Used to denote page to be gotten ride of                                   
	int replace;

	//used in comparision                                                        
	deque<int> compare;

	while ( (page = myPageFactory->getPage()) != -1 )
	{
		fault = false; // assume false until we have a fault.                     


		if ( hit(page) == -1 )
		{
			fault = true;
			if(marker < (NUM_FRAMES)){ //this is used to situate the first four    
				compare.push_back(page);
				frames[marker] = page;
				marker++;
			}

			else{
				replace = compare[0]; //designates which element should be replaced
				compare.pop_front(); //gets rid of the one in front                 
								compare.push_back(page); //inserts the one in back                  
								for(int i = 0; i < NUM_FRAMES; i++){
									if(frames[i] == replace){
										frames[i] = page; //replaces the correct one                  
									}
								}

								// for(int i = 0; i < compare.size(); i++){                         
								// cout << compare[i];                                              
								// }                                                                
								//cout << endl;                                                     
							}
						}

						else if(hit(page) != -1){ //This is to put the one that just appear into  
							for(int i = 0; i < compare.size(); i++){ // the back.                  
								if(compare[i] == page){
									compare.erase(compare.begin()+ i);
								}
							}
							compare.push_back(page);
						}


						  display(page, frames, fault);
						}
					}




