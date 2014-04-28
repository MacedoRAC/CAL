#include "Project.h"
#include "loader.h"
#include "menu.h"
#include "graphviewer.h"


#include <sstream>
#include <numeric>
#include <set>
#include <cassert>
#include <cmath>
#include <algorithm>


#define WHITESPACE_GRAPHVIEWER " \b" ///< hack to remove vertex and edge labels (empty string or only whitespace does not work)
#define WINDOW_WIDTH 800 ///< GraphViewer width
#define WINDOW_HEIGHT 600 ///< GraphViewer height
#define WINDOW_MARGIN 40 ///< Used when redimensioning the graph node's position

Menu* Project::_menu = Loader<Menu>("ProjectThesisMenu.txt").Load();

Project::Project(string theme,bool hasMaster,bool hasStudent, Owner* owner){
	this->theme=theme;
	this->hasMaster=hasMaster;
	this->hasStudent=hasStudent;
	this->owner=owner;
}

Project::~Project(){
}

bool Project::isHasMaster() const {
	return hasMaster;
}

void Project::setHasMaster(bool hasMaster) {
	this->hasMaster = hasMaster;
}

bool Project::isHasStudent() const {
	return hasStudent;
}

void Project::setHasStudent(bool hasStudent) {
	this->hasStudent = hasStudent;
}

string Project::getTheme() const {
	return theme;
}

void Project::setTheme(string theme) {
	this->theme = theme;
}

Owner* Project::getOwner() const {
	return owner;
}

void Project::setOwner(Owner* owner) {
	this->owner = owner;
}

void Project::ViewGraph(Graph<Person*> graph, int NPeople, int NProjects){
	int incr = 0 ;
	
	 if (!_graphViewer)
	    {
	        // new window
	        _graphViewer = new GraphViewer(WINDOW_WIDTH, WINDOW_HEIGHT, false);
	        //_graphViewer->setBackground("water1.jpg");
	        _graphViewer->createWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
	    }
	    else
	    {

		}
		graph.DrawView(_graphViewer,NPeople, NProjects);
		/**
		vector<Vertex<Person*> *> VertexSet = graph.getVertexSet();
		for (int i = 0; i < NPeople; i++) {
		 		_graphViewer->addNode(i + 1, 50, 120 + 120 * i);
				_graphViewer->setVertexLabel(i+1,VertexSet[i]->getInfo().getName());
			}	    

			for (int i = NPeople; i < NPeople + NProjects; i++) {
				_graphViewer->addNode(i + 1, 350, 120 + 120 * (i -NPeople));
				_graphViewer->setVertexLabel(i+1,VertexSet[i]->getInfo().getName());

			}
	
			for (int i = NPeople + NProjects; i < graph.getVertexSet.size(); i++) {
				_graphViewer->addNode(i + 1, 650, 120 + 120 * (i - NPeople - NProjects));
				_graphViewer->setVertexLabel(i+1,VertexSet[i]->getInfo().getName());

			}

			for (int i = 0; i < graph.getVertexSet.size(); i++) {
				for (int j = 0; j < VertexSet[i]->getEdges().size(); j++) {
					int l = graph.getVertexSet[i]->getEdges()[j].getDest()->getInfo().getId();
					_graphViewer->addEdge(incr, i + 1, l, EdgeType::DIRECTED);

					double s = VertexSet[i]->getEdges()[j].getWeight();

					_graphViewer->setEdgeWeight(incr, s+1);

					if (VertexSet[i]->getEdges()[j].getDest().getInfo().isMarried()) {
							_graphViewer->setEdgeThickness(incr,4);
					} else
						_graphViewer->setEdgeThickness(incr,1);

					incr++;
				}
			}
			*/
	    }
