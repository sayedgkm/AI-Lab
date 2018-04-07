import java.util.Random;


public class FirstChoiceHillClimb 
{
	TSP tsp;
	int sigma;
	
	public FirstChoiceHillClimb(TSP tsp, int sigma) 
	{
		// TODO Auto-generated constructor stub
		this.tsp = tsp;
		this.sigma = sigma;
	}
	
	/**
	 * Main loop of your local search algorithm. 
	 * After the search is complete, create a SolutionInfo Object 
	 * with related information and return to the caller to generate aggregated results
	 * @return
	 */
        private static Random random = new Random(System.currentTimeMillis());
	public SolutionInfo run() 
	{
		//Main loop of your local search algorithm. 
            Route current = new Route(this.tsp);
            Route neighbor=new Route (this.tsp);
            OneOneExchange h1 = new OneOneExchange();
            Or_Opt h2 = new Or_Opt(); 
            
            int count = 0;
            while(true) {
                int i ;
                for(i = 0;i<sigma;i++) {
                    Random rand = new Random();
                    double ran =rand.nextFloat();
                    if(ran<0.5) neighbor=h1.apply(current);
                    else neighbor=h2.apply(current);
                    if(neighbor.getCost()<current.getCost()) break;
                    
                }
               // System.out.println(i+" "+sigma);
                if(i==sigma) {
                    SolutionInfo si = new SolutionInfo(current,count);	
                    return si;
                }
                current = neighbor;
                count++;
            }
		
	
           
	}
	
	
	
	
	
}
