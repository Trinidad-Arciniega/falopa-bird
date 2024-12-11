#include "Parallax.hpp"

Parallax::Parallax(){
    initiated=false;
    score=0;
    if(!obsT.loadFromFile("resources/sprites/pipe.png")){
        std::cout<<"Error al cargar la textura resources/sprites/pipe.png"<<'\n'
    }
    if(!obsT.loadFromFile("resources/sprites/base.png")){
        std::cout<<"Error al cargar la textura resources/sprites/base.png"<<'\n'
    }
        
    srand(time(NULL));

    obstacle.push_back(Obstacle(obsT,500,100+rand()%250));
    obstacle.push_back(Obstacle(obsT,800,100+rand()%250));

    sf::Sprite nSpr;
    nSpr.setTexture(baseT);
    NSpr.setPosition(0,700-112);
    nSpr.setScale(1.5f,1.5f);
    bases.push_back(nSpr);
}

void Parallax
    for(int i = 0; i < (int)bases.size(); i++){
        if(bases[i].getPosition().x<-(336*1.5f)){
            bases.erase(bases.begin()+i);
            continue;
        }

        if(bases[i].getPosition().x<=0){
            sf::Sprite nSpr=bases[i];
            nSpr.setPosition(nSpr.getPosition().x+336*1.5f,700-112);
            bases.push_back(nSpr);
        }
    }

    for(int i = 0; i < (int)bases.size(); i++){
        bases[i].move(-2.5f,0);
    }

    if(!initiated) return;

    int ult = (int)obstacles.size()-1;
    for(int i = 0; i < (int)obstacles.size(); i++){
        if(obstacles[i].GetPosition().x<0&&obstacles[i].GetPosition().x>=-3){
            obstacles.push_back(Obstacle(obsT,obstacles[ult].GetPosition().x+350,100+rand()%250));
        }

        if(obstacle[i].GetPosition().x<100&&i>last){
            last=i;
            sxore++;
        }

        if(obstacle[i].GetPosition().x<=-100) obstacles.erase(obstacles.begin()+i);

    }

    for(int i = 0; i < (int)obstacles.size(); i++){
        obstacles[i].Update();
    }


bool Parallax::Collision(sf::IntRect rect){
    for(int i = 0; i < (int)obstacles.size(); i++){
        if(obstacles[i].Collision(rect)) return true;
    }
    return false;
}

int Parallax::Score(){
    return score;
}

void Parallax::Initiated(){
    initiated=true;
}

void Parallax::draw(sf::RenderTarget &rt, sf::RenderStates rs) const{
    for(int i = 0; i < (int)obstacles.size(); i++) rt.draw(obstacles[i],rs);
    for(int i = 0; i < (int)bases.size(); i++) rt.draw(bases[i],rs);
}