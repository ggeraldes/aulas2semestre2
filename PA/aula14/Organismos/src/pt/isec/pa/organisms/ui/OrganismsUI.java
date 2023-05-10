package pt.isec.pa.organisms.ui;

import pt.isec.pa.organisms.gameengine.IGameEngineEvolve;
import pt.isec.pa.organisms.model.ModelLog;
import pt.isec.pa.organisms.model.data.Environment;

public class OrganismsUI implements IGameEngineEvolve {
    Environment environment;

    public OrganismsUI(Environment environment) { this.environment = environment; }


    public void show() {

        char [][] env = environment.getEnvironment();
        System.out.println();
        for(int y=0;y<env.length;y++) {
            for(int x = 0; x< env[0].length;x++)
                System.out.print(env[y][x]);
            System.out.println();
        }
        if(environment.onlyOneSpecies())
            gameEngine.stop();
    }
}
