#pragma once
class World
{
public:
	// Toutes les ressources du jeu

	private:
		int golds;
		int rocks;
		int wood;
		int freeWorkers;
		int goldWorkers;
		int rockWorkers;
		int woodWorkers;
	
	public:
		int getGolds() const;
		void setGolds(int golds);
		int getRocks() const;
		void setRocks(int rocks);
		int getWood() const;
		void setWood(int wood);
		int getFreeWorkers() const;
		void setFreeWorkers(int workers);
		int getGoldWorkers() const;
		void setGoldWorkers(int gold_workers);
		int getRockWorkers() const;
		void setRockWorkers(int rock_workers);
		int getWoodWorkers() const;
		void setWoodWorkers(int wood_workers);


		World(int golds, int rocks, int wood, int freeWorkers, int goldWorkers, int rockWorkers, int woodWorkers);

		World();
		~World();
};

