/***********************************************************************        
* Program:                                                                      
*    Lab PageReplacement                                                        
*    Brother Jones, CS 345                                                      
* Author:                                                                       
*    Donovan Gregory                                                            
* Summary:                                                                      
*    Implements the first in, first out algorithm for page tables.              
*                                                                               
************************************************************************/

#include "vmalgorithm.h"

/**************************************************************************     
 * Function:                                                                    
 *    void FIFO::execute() - Executes the FIFO page replacement algorithm       
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
void FIFO::execute()
{
	// Keep track of faults,                                                     
	bool fault;

	// Holds the accessed page                                                   
	int page;

	// Keepes track of pagetable number                                          
	int marker = 0;

	while ( (page = myPageFactory->getPage()) != -1 )
		{
			fault = false; // assume false until we have a fault.                     


			if ( hit(page) == -1 )
			{
				// if the page was not found, choose the next that was in              
				frames[marker] = page;
				fault = true; //Show that there was a fault                            
				marker++; // move the marker to the next number in the array           
				if (marker > (NUM_FRAMES -1)){
					marker = 0; //reset marker once we have reach array boundary        
				}
			}

			display(page, frames, fault);
		}

	}
