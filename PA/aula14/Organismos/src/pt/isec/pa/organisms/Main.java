package pt.isec.pa.organisms;

import pt.isec.pa.organisms.gameengine.GameEngine;
import pt.isec.pa.organisms.gameengine.IGameEngine;
import pt.isec.pa.organisms.gameengine.IGameEngineEvolve;
import pt.isec.pa.organisms.model.EnvironmentManager;
import pt.isec.pa.organisms.model.data.Environment;
import pt.isec.pa.organisms.model.data.Evolver;
import pt.isec.pa.organisms.model.data.Virus;
import pt.isec.pa.organisms.ui.OrganismsLanternaUI;
import pt.isec.pa.organisms.ui.OrganismsUI;

import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        EnvironmentManager environment = new EnvironmentManager();

        OrganismsLanternaUI ui = new OrganismsLanternaUI(environment);

        GameEngine gameEngine = new GameEngine();
        gameEngine.registerClient((g,t) -> {
            if (!environment.evolve())
                g.stop();
        });
        gameEngine.registerClient((g,t) -> ui.show() );

        gameEngine.start(500);

        gameEngine.waitForTheEnd();
    }
    static int i = 0;
}
