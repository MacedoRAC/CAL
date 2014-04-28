#include<vector>
#include"Person.h"
#include"Master.h"


void thesisAttribuitiontoStudent(Graph<Person>* graph) { //applies stable marriage algorithm

	int end, min = -1;

	//go through students
	for (int i = 0; i < graph->getNumberOfStudents(); i++) {

		for (int j = 0; j < graph->getVertexSet()[i]->getAdj().size(); j++) {

			if ((min == -1 || graph->vertexSet[i]->getAdj()[j].getWeight() < min)
					&& !graph->getVertexSet()[i]->getAdj()[j].isRejected()) {
				min = graph->getVertexSet()[i]->getAdj()[j].getWeight();
				end = j;
			}

		}
		//put selected edges on both directions
		if (min != -1) {
			graph->getVertexSet()[i]->getAdj()[end].setProposed(true);
			graph->getVertexSet()[i]->getAdj()[end].setRejected(true);
			Vertex<Person> * p = graph->getVertexSet()[i]->getAdj()[end].getDest();
			for (int c = 0; c < p->getAdj().size(); c++) {
				if (p->getAdj()[c].dest->info == graph->getVertexSet()[i]->getInfo()) {
					p->getAdj()[c].setProposed(true);
				}
			}
		}
	}


	for (int i = graph->getNumberOfStudents(); i < graph->getNumberOfStudents() + graph->getNumberOfOwners(); i++) {
		min = -1;

		for (int j = 0; j < graph->getVertexSet()[i]->getAdj().size(); j++) {
			if (graph->getVertexSet()[i]->getAdj()[j].isProposed() && !graph->getVertexSet()[i]->getAdj()[j].isRejected()) {
				graph->getVertexSet()[i]->getAdj()[j].setRejected(true);

				if (min == -1 || graph->getVertexSet()[i]->getAdj()[j].getWeight() < min) {
					min = graph->getVertexSet()[i]->getAdj()[j].getWeight();
					end = j;
				}
			}
		}
		if (min != -1) {

			graph->getVertexSet()[i]->getAdj()[end].setRejected(false);
			Vertex<Person>* p = graph->getVertexSet()[i]->getAdj()[end].getDest();
			for (int c = 0; c < p->getAdj().size(); c++) {
				if (p->getAdj()[c].getDest()->getInfo() == graph->getVertexSet()[i]->getInfo())
					p->getAdj()[c].setRejected(false);
			}
		}
	}

	//check if all students have thesis
	if (!allStudentsHaveThesis(graph))
		thesisAttribuitiontoStudent(graph);

}


bool allStudentsHaveThesis(Graph<Person>* graph) {
	bool result;
	int inc = 0;
	for (int i = 0; i < graph->getNumberOfStudents(); i++) {
		result = false;
		for (int j = 0; j < graph->getVertexSet()[i]->getAdj().size(); j++) {

			if (graph->getVertexSet()[i]->getAdj()[j].isProposed() && !graph->getVertexSet()[i]->getAdj()[j].isRejected()) {
				result = true;
				inc++;
			}
		}
	}
	return result;
}


void thesisAttribuitionMasters(Graph<Person>* graph,  vector<vector<int>> IDmatrix) {

	//getting total masters iterations
	int mastersTotalProjects = 0;

	for (int i = graph->getNumberOfStudents() + graph->getNumberOfOwners(); i < graph->getVertexSet().size(); i++){
		Master m= graph->getVertexSet()[i]->getInfo();
		mastersTotalProjects += m.getNmax();
	}

	cout << "Total of masters is: " << mastersTotalProjects << " \n";


	//getting number of thesis attributed to students

	int studentsProjects = 0;

	for (int i = graph->getNumberOfStudents(); i < graph->getNumberOfStudents() + graph->getNumberOfOwners(); i++) {

		for (int j = 0; j < graph->getVertexSet()[i]->getAdj().size(); j++) {
			if (graph->getVertexSet()[i]->getAdj()[j].isProposed() && !graph->getVertexSet()[i]->getAdj()[j].isRejected())
				studentsProjects++;
		}

	}

	cout << "Total of projects attributed do students is: " << studentsProjects << " \n";

	int sizeMatrix =0;
	if (mastersTotalProjects >= studentsProjects) {
		sizeMatrix = mastersTotalProjects + 1;
	} else
		sizeMatrix = studentsProjects + 1;

	//put in IDmatrix owner's and master's id's
	for (int i = 0; i < sizeMatrix; i++) {
		for (int j = 0; j < sizeMatrix; j++) {
			IDmatrix[i][j] = -1;
		}
	}

	int r = 1;
	for (int i = graph->getNumberOfStudents() + graph->getNumberOfOwners(); i < graph->getVertexSet().size(); i++) {
		Master m= graph->getVertexSet()[i]->getInfo();
		for (int j = 0; j < m.getNmax(); j++) {
			IDmatrix[0][r] = graph->getVertexSet()[i]->getInfo().getId();
			r++;

		}

	}
	r = 1;
	for (int i = graph->getNumberOfStudents(); i < graph->getNumberOfStudents() + graph->getNumberOfOwners(); i++) {
		bool con = false;

		for (int j = 0; j < graph->getVertexSet()[i]->getAdj().size(); j++) {
			if (graph->getVertexSet()[i]->getAdj()[j].isProposed()	&& !graph->getVertexSet()[i]->getAdj()[j].isRejected()) {
				con = true;
			}
		}
		if (con) {
			IDmatrix[r][0] = graph->getVertexSet()[i]->getInfo().getId();
			r++;
		}
	}

	for (int i = 1; i < sizeMatrix; i++) {
		int proT = IDmatrix[i][0];

		for (int j = 1; j < sizeMatrix; j++) {
			int supT = IDmatrix[0][j];

			for (int c = 0; c < graph->getVertexSet()[supT - 1]->getAdj().size(); c++) {

				if (graph->getVertexSet()[supT - 1]->getAdj()[c].getDest()->getInfo().getId() == proT) {
					IDmatrix[i][j] = graph->getVertexSet()[supT - 1]->getAdj()[c].getWeight();
				}
			}

		}
	}

	int max = -1;
	for (int i = 1; i < sizeMatrix; i++) {
		for (int j = 1; j < sizeMatrix; j++) {
			if (IDmatrix[i][j] > max) {
				max = IDmatrix[i][j];
			}
		}
	}

	for (int i = 1; i < sizeMatrix; i++) {
		for (int j = 1; j < sizeMatrix; j++) {
			if (IDmatrix[i][j] == -1) {
				IDmatrix[i][j] = max;
			}
		}
	}

	//shrink columns
	for (int i = 1; i < sizeMatrix; i++) {
		int minc = -1;

		for (int j = 1; j < sizeMatrix; j++) {
			if (minc == -1 || IDmatrix[j][i] < minc) {
				minc = IDmatrix[j][i];
			}
		}
		for (int j = 1; j < sizeMatrix; j++) {
			IDmatrix[j][i] -= minc;
		}

	}


	//shrink lines
	for (int i = 1; i < sizeMatrix; i++) {
		int minc = -1;

		for (int j = 1; j < sizeMatrix; j++) {
			if (minc == -1 || IDmatrix[i][j] < minc) {
				minc = IDmatrix[i][j];
			}
		}
		for (int j = 1; j < sizeMatrix; j++) {
			IDmatrix[i][j] -= minc;
		}

	}

	bool rejectedj[sizeMatrix];
	for (int i = 0; i < sizeMatrix; i++)
		rejectedj[i] = false;
	bool rejectedi[sizeMatrix];
	for (int i = 0; i < sizeMatrix; i++)
		rejectedi[i] = false;
	bool tickedj[sizeMatrix];
	for (int i = 0; i < sizeMatrix; i++)
		tickedj[i] = false;
	bool tickedi[sizeMatrix];
	for (int i = 0; i < sizeMatrix; i++)
		tickedi[i] = false;
	bool accepted[sizeMatrix][sizeMatrix];
	int atributed = 0;

	bool assigned = false;
	bool multipelchoices = false;
	bool finished = false;
	bool ticked = false;
	while (!finished) {
		cout << "iteracion\n";
		assigned = false;
		ticked = false;
		multipelchoices = false;
		atributed = 0;

		for (int i = 0; i < sizeMatrix; i++)
			rejectedj[i] = false;

		for (int i = 0; i < sizeMatrix; i++)
			rejectedi[i] = false;

		for (int i = 0; i < sizeMatrix; i++)
			tickedj[i] = false;

		for (int i = 0; i < sizeMatrix; i++)
			tickedi[i] = false;
		for (int i = 0; i < sizeMatrix; i++) {
			for (int j = 0; j < sizeMatrix; j++) {
				accepted[i][j] = false;
			}
		}

		while (!assigned) {
			cout << "  itere  " << endl;
			for (int i = 1; i < sizeMatrix; i++) {

				int znum = 0;
				for (int j = 1; j < sizeMatrix; j++) {
					if (IDmatrix[i][j] == 0 && !rejectedj[j] && !rejectedi[i]) {
						znum++;
					}
				}
				if (znum == 1) {
					for (int j = 1; j < sizeMatrix; j++) {
						if (IDmatrix[i][j] == 0 && !rejectedj[j]
						                                    && !rejectedi[i]) {
							accepted[i][j] = true;
							rejectedj[j] = true;
							rejectedi[i] = true;
							atributed++;
						}
					}
				}
				if (znum > 1 && multipelchoices) {
					for (int j = 1; j < sizeMatrix; j++) {
						if (IDmatrix[i][j] == 0 && !rejectedj[j] && !rejectedi[i]
						                                                     && multipelchoices) {
							accepted[i][j] = true;
							rejectedj[j] = true;
							rejectedi[i] = true;
							atributed++;
							multipelchoices = false;
						}
					}

				}

			}
			for (int i = 1; i < sizeMatrix; i++) {

				int znum = 0;
				for (int j = 1; j < sizeMatrix; j++) {
					if (IDmatrix[j][i] == 0 && !rejectedi[j] && !rejectedj[i]) {
						znum++;
					}
				}
				if (znum == 1) {
					for (int j = 1; j < sizeMatrix; j++) {
						if (IDmatrix[j][i] == 0 && !rejectedi[j]
						                                    && !rejectedj[i]) {
							accepted[j][i] = true;
							rejectedi[j] = true;
							rejectedj[i] = true;
							atributed++;
						}
					}
				}
				if (znum > 1 && multipelchoices) {
					for (int j = 1; j < sizeMatrix; j++) {
						if (IDmatrix[j][i] == 0 && !rejectedi[j] && !rejectedj[i]
						                                                     && multipelchoices) {
							accepted[j][i] = true;
							rejectedi[j] = true;
							rejectedj[i] = true;
							atributed++;
							multipelchoices = false;
						}
					}

				}

			}

			assigned = true;
			for (int i = 1; i < sizeMatrix; i++) {
				for (int j = 1; j < sizeMatrix; j++) {
					if (IDmatrix[i][j] == 0 && !rejectedj[j] && !rejectedi[i]) {

						assigned = false;

					}
				}
			}
			if (atributed == sizeMatrix - 1) {
				assigned = true;
			}

			multipelchoices = false;
			for (int i = 1; i < sizeMatrix; i++) {
				int znum = 0;
				for (int j = 1; j < sizeMatrix; j++) {
					if (IDmatrix[i][j] == 0 && rejectedj[j] != -1
							&& rejectedi[i] != -1) {

						znum++;

					}
				}
				if (znum > 1) {
					multipelchoices = true;
				}
			}
			if (!multipelchoices) {
				for (int j = 1; j < sizeMatrix; j++) {
					int znum = 0;
					for (int i = 1; i < sizeMatrix; i++) {
						if (IDmatrix[i][j] == 0 && rejectedj[j] != -1
								&& rejectedi[i] != -1) {

							znum++;

						}
					}
					if (znum > 1) {
						multipelchoices = true;
					}
				}
			}
			//print
			for (int i = 0; i < sizeMatrix; i++) {
				for (int j = 0; j < sizeMatrix; j++) {
					cout << IDmatrix[i][j] << "|";
				}
				cout << endl;
			}
		}

		cout << "assginment numbers: " << atributed << "\n";
		for (int i = 0; i < sizeMatrix; i++) {
			for (int j = 0; j < sizeMatrix; j++) {
				cout << accepted[i][j] << "|";
			}
			cout << endl;

		}
		cout << endl;

		if (atributed == sizeMatrix - 1) {
			cout << "hungarian done\n";
			finished = true;
			ticked = true;
		}
		if (!ticked) {

			for (int i = 1; i < sizeMatrix; i++) {
				if (!rejectedi[i]) {
					tickedi[i] = true;

				}
			}
			for (int i = 1; i < sizeMatrix; i++) {
				cout << tickedi[i] << "|";
			}
			cout << "\n";
			for (int i = 1; i < sizeMatrix; i++) {
				cout << tickedj[i] << "|";
			}
			cout << "\n";
			cout << "\n";

			while (!ticked) {
				cout << "starting tick process\n";
				ticked = true;
				for (int i = 0; i < sizeMatrix; i++) {
					if (tickedi[i]) {

						for (int j = 0; j < sizeMatrix; j++) {
							if (IDmatrix[i][j] == 0 && !tickedj[j]) {
								ticked = false;
								tickedj[j] = true;

							}

						}

					}
				}
				for (int j = 0; j < sizeMatrix; j++) {
					if (tickedj[j]) {

						for (int i = 0; i < sizeMatrix; i++) {
							if (!tickedi[i] && accepted[i][j]) {
								ticked = false;
								tickedi[i] = true;

							}

						}

					}
				}
				for (int i = 1; i < sizeMatrix; i++) {
					cout << tickedi[i] << "|";
				}
				cout << "\n";
				for (int i = 1; i < sizeMatrix; i++) {
					cout << tickedj[i] << "|";
				}
				cout << "\n";
				cout << "\n";
			}
		}

		for (int i = 0; i < sizeMatrix; i++) {
			if (tickedi[i]) {
				tickedi[i] = false;
			} else
				tickedi[i] = true;
		}

		for (int i = 1; i < sizeMatrix; i++) {
			cout << tickedi[i] << "|";
		}
		cout << "\n";
		for (int i = 1; i < sizeMatrix; i++) {
			cout << tickedj[i] << "|";
		}
		cout << "\n";
		cout << "\n";
		cout << "all ticked\n";
		int minT = -1;

		for (int i = 1; i < sizeMatrix; i++) {
			for (int j = 1; j < sizeMatrix; j++) {
				if ((IDmatrix[i][j] < minT || minT == -1) && !tickedi[i]
				                                                    && !tickedj[j]) {
					minT = IDmatrix[i][j];
				}

			}
		}
		for (int i = 1; i < sizeMatrix; i++) {
			for (int j = 1; j < sizeMatrix; j++) {
				if (!tickedi[i] && !tickedj[j]) {
					IDmatrix[i][j] -= minT;
				}
				if (tickedi[i] && tickedj[j]) {
					IDmatrix[i][j] += minT;
				}

			}
		}

		cout << "minT = " << minT << endl;
		//print
		for (int i = 0; i < sizeMatrix; i++) {
			for (int j = 0; j < sizeMatrix; j++) {
				cout << IDmatrix[i][j] << "|";
			}
			cout << endl;
		}

		for (int i = 1; i < sizeMatrix; i++) {

			int aci = IDmatrix[i][0];
			for (int j = 1; j < sizeMatrix; j++) {

				if (accepted[i][j]) {
					int acj = IDmatrix[0][j];
					for (int c = 0; c < graph->getVertexSet()[acj - 1]->getAdj().size(); c++) {
						if (graph->getVertexSet()[acj - 1]->getAdj()[c].getDest()->getInfo().getId() == aci) {
							graph->getVertexSet()[acj - 1]->getAdj()[c].setProposed(true);
						}
					}
				}
			}
		}

	}

}
