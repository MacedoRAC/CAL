void applyStableMarriage();
bool studentsLinked();
void applyHungAlg();


template<class T>
void Graph<T>::applyStableMarriage() {

	//percorrer estudantes
	for (int i = 0; i < studentsN; i++) {
		int min = -1;
		int edj;
		for (int j = 0; j < vertexSet[i]->adj.size(); j++) {
			if ((min == -1 || vertexSet[i]->adj[j].weight < min)
					&& !vertexSet[i]->adj[j].rejected) {
				min = vertexSet[i]->adj[j].weight;
				edj = j;
			}

		}
		//colocar as ligaçoes selecioanas nos 2 sentidso
		if (min != -1) {
			vertexSet[i]->adj[edj].proposed = true;
			vertexSet[i]->adj[edj].rejected = true;
			Vertex<T> * de = vertexSet[i]->adj[edj].dest;
			for (int c = 0; c < de->adj.size(); c++) {
				if (de->adj[c].dest->info == vertexSet[i]->info) {
					de->adj[c].proposed = true;
				}
			}
		}
	}

	for (int i = studentsN; i < studentsN + projectsN; i++) {
		int min = -1;
		int edj;
		for (int j = 0; j < vertexSet[i]->adj.size(); j++) {
			cout << "testing conection of edge to: "
					<< vertexSet[i]->adj[j].dest->info.print() << endl;
			if (vertexSet[i]->adj[j].proposed
					&& !vertexSet[i]->adj[j].rejected) {
				vertexSet[i]->adj[j].rejected = true;

				if (min == -1 || vertexSet[i]->adj[j].weight < min) {
					min = vertexSet[i]->adj[j].weight;
					edj = j;
				}
			}
		}
		if (min != -1) {

			vertexSet[i]->adj[edj].rejected = false;
			Vertex<T> * de = vertexSet[i]->adj[edj].dest;
			cout << "apor o destino : " << de->info.print() << endl;
			for (int c = 0; c < de->adj.size(); c++) {
				if (de->adj[c].dest->info == vertexSet[i]->info) {

					de->adj[c].rejected = false;
				}
			}
		}
	}

	//se nao tiverem todos uma ligaçao
	if (!studentsLinked())
		this->applyStableMarriage();

}


template<class T>
bool Graph<T>::studentsLinked() {
	bool n;
	int errm = 0;
	for (int i = 0; i < studentsN; i++) {
		n = false;
		for (int j = 0; j < vertexSet[i]->adj.size(); j++) {

			if (vertexSet[i]->adj[j].proposed
					&& !vertexSet[i]->adj[j].rejected) {
				n = true;
				errm++;
			}

		}
		if (n == false) {
			return false;
		}
	}
	return true;
}

template<class T>
void Graph<T>::applyHungAlg() {
	//getting total supervisors iterations
	int sptN = 0;
	for (int i = studentsN + projectsN; i < vertexSet.size(); i++) {
		sptN += vertexSet[i]->info.getNumMax();
	}
	cout << "Total of supervisors it: " << sptN << " \n";
	//getting number of projects with students
	int prN = 0;
	for (int i = studentsN; i < studentsN + projectsN; i++) {

		for (int j = 0; j < vertexSet[i]->adj.size(); j++) {
			if (vertexSet[i]->adj[j].proposed
					&& !vertexSet[i]->adj[j].rejected) {
				prN++;
			}
		}

	}
	cout << "Total of projects picked: " << prN << " \n";

	int matrixSize = 0;

	if (sptN >= prN) {
		matrixSize = sptN + 1;
	} else
		matrixSize = prN + 1;

	cout << "Matrix size: " << matrixSize << endl;

	int matrix[matrixSize][matrixSize];
	//colocar ids de projectos e sueprvisores

	for (int i = 0; i < matrixSize; i++) {
		for (int j = 0; j < matrixSize; j++) {
			matrix[i][j] = -1;
		}
	}

	int r = 1;
	for (int i = studentsN + projectsN; i < vertexSet.size(); i++) {
		for (int j = 0; j < vertexSet[i]->info.getNumMax(); j++) {
			matrix[0][r] = vertexSet[i]->info.getId();
			r++;

		}

	}
	r = 1;
	for (int i = studentsN; i < studentsN + projectsN; i++) {
		bool con = false;

		for (int j = 0; j < vertexSet[i]->adj.size(); j++) {
			if (vertexSet[i]->adj[j].proposed
					&& !vertexSet[i]->adj[j].rejected) {
				con = true;

			}
		}
		if (con) {
			matrix[r][0] = vertexSet[i]->info.getId();
			r++;
		}
	}

	for (int i = 1; i < matrixSize; i++) {
		int proT = matrix[i][0];

		for (int j = 1; j < matrixSize; j++) {
			int supT = matrix[0][j];

			for (int c = 0; c < vertexSet[supT - 1]->adj.size(); c++) {

				if (vertexSet[supT - 1]->adj[c].dest->info.getId() == proT) {
					matrix[i][j] = vertexSet[supT - 1]->adj[c].weight;
				}
			}

		}
	}

	int max = -1;
	for (int i = 1; i < matrixSize; i++) {
		for (int j = 1; j < matrixSize; j++) {
			if (matrix[i][j] > max) {
				max = matrix[i][j];
			}
		}
	}
	cout << "o maximo é: " << max << endl;

	for (int i = 1; i < matrixSize; i++) {
		for (int j = 1; j < matrixSize; j++) {
			if (matrix[i][j] == -1) {
				matrix[i][j] = max;
			}
		}
	}

	//print
	for (int i = 0; i < matrixSize; i++) {
		for (int j = 0; j < matrixSize; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	//reduzir colunas

	for (int i = 1; i < matrixSize; i++) {
		int minc = -1;

		for (int j = 1; j < matrixSize; j++) {
			if (minc == -1 || matrix[j][i] < minc) {
				minc = matrix[j][i];
			}
		}
		for (int j = 1; j < matrixSize; j++) {
			matrix[j][i] -= minc;
		}

	}
	//print
	for (int i = 0; i < matrixSize; i++) {
		for (int j = 0; j < matrixSize; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	//reduzir filas

	for (int i = 1; i < matrixSize; i++) {
		int minc = -1;

		for (int j = 1; j < matrixSize; j++) {
			if (minc == -1 || matrix[i][j] < minc) {
				minc = matrix[i][j];
			}
		}
		for (int j = 1; j < matrixSize; j++) {
			matrix[i][j] -= minc;
		}

	}
	//print
	for (int i = 0; i < matrixSize; i++) {
		for (int j = 0; j < matrixSize; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	bool rejectedj[matrixSize];
	for (int i = 0; i < matrixSize; i++)
		rejectedj[i] = false;
	bool rejectedi[matrixSize];
	for (int i = 0; i < matrixSize; i++)
		rejectedi[i] = false;
	bool tickedj[matrixSize];
	for (int i = 0; i < matrixSize; i++)
		tickedj[i] = false;
	bool tickedi[matrixSize];
	for (int i = 0; i < matrixSize; i++)
		tickedi[i] = false;
	bool accepted[matrixSize][matrixSize];
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

		for (int i = 0; i < matrixSize; i++)
			rejectedj[i] = false;

		for (int i = 0; i < matrixSize; i++)
			rejectedi[i] = false;

		for (int i = 0; i < matrixSize; i++)
			tickedj[i] = false;

		for (int i = 0; i < matrixSize; i++)
			tickedi[i] = false;
		for (int i = 0; i < matrixSize; i++) {
			for (int j = 0; j < matrixSize; j++) {
				accepted[i][j] = false;
			}
		}

		while (!assigned) {
			cout << "  itere  " << endl;
			for (int i = 1; i < matrixSize; i++) {

				int znum = 0;
				for (int j = 1; j < matrixSize; j++) {
					if (matrix[i][j] == 0 && !rejectedj[j] && !rejectedi[i]) {
						znum++;
					}
				}
				if (znum == 1) {
					for (int j = 1; j < matrixSize; j++) {
						if (matrix[i][j] == 0 && !rejectedj[j]
						                                    && !rejectedi[i]) {
							accepted[i][j] = true;
							rejectedj[j] = true;
							rejectedi[i] = true;
							atributed++;
						}
					}
				}
				if (znum > 1 && multipelchoices) {
					for (int j = 1; j < matrixSize; j++) {
						if (matrix[i][j] == 0 && !rejectedj[j] && !rejectedi[i]
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
			for (int i = 1; i < matrixSize; i++) {

				int znum = 0;
				for (int j = 1; j < matrixSize; j++) {
					if (matrix[j][i] == 0 && !rejectedi[j] && !rejectedj[i]) {
						znum++;
					}
				}
				if (znum == 1) {
					for (int j = 1; j < matrixSize; j++) {
						if (matrix[j][i] == 0 && !rejectedi[j]
						                                    && !rejectedj[i]) {
							accepted[j][i] = true;
							rejectedi[j] = true;
							rejectedj[i] = true;
							atributed++;
						}
					}
				}
				if (znum > 1 && multipelchoices) {
					for (int j = 1; j < matrixSize; j++) {
						if (matrix[j][i] == 0 && !rejectedi[j] && !rejectedj[i]
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
			for (int i = 1; i < matrixSize; i++) {
				for (int j = 1; j < matrixSize; j++) {
					if (matrix[i][j] == 0 && !rejectedj[j] && !rejectedi[i]) {

						assigned = false;

					}
				}
			}
			if (atributed == matrixSize - 1) {
				assigned = true;
			}

			multipelchoices = false;
			for (int i = 1; i < matrixSize; i++) {
				int znum = 0;
				for (int j = 1; j < matrixSize; j++) {
					if (matrix[i][j] == 0 && rejectedj[j] != -1
							&& rejectedi[i] != -1) {

						znum++;

					}
				}
				if (znum > 1) {
					multipelchoices = true;
				}
			}
			if (!multipelchoices) {
				for (int j = 1; j < matrixSize; j++) {
					int znum = 0;
					for (int i = 1; i < matrixSize; i++) {
						if (matrix[i][j] == 0 && rejectedj[j] != -1
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
			for (int i = 0; i < matrixSize; i++) {
				for (int j = 0; j < matrixSize; j++) {
					cout << matrix[i][j] << "|";
				}
				cout << endl;
			}
		}

		cout << "assginment numbers: " << atributed << "\n";
		for (int i = 0; i < matrixSize; i++) {
			for (int j = 0; j < matrixSize; j++) {
				cout << accepted[i][j] << "|";
			}
			cout << endl;

		}
		cout << endl;

		if (atributed == matrixSize - 1) {
			cout << "hungarian done\n";
			finished = true;
			ticked = true;
		}
		if (!ticked) {

			for (int i = 1; i < matrixSize; i++) {
				if (!rejectedi[i]) {
					tickedi[i] = true;

				}
			}
			for (int i = 1; i < matrixSize; i++) {
				cout << tickedi[i] << "|";
			}
			cout << "\n";
			for (int i = 1; i < matrixSize; i++) {
				cout << tickedj[i] << "|";
			}
			cout << "\n";
			cout << "\n";

			while (!ticked) {
				cout << "starting tick process\n";
				ticked = true;
				for (int i = 0; i < matrixSize; i++) {
					if (tickedi[i]) {

						for (int j = 0; j < matrixSize; j++) {
							if (matrix[i][j] == 0 && !tickedj[j]) {
								ticked = false;
								tickedj[j] = true;

							}

						}

					}
				}
				for (int j = 0; j < matrixSize; j++) {
					if (tickedj[j]) {

						for (int i = 0; i < matrixSize; i++) {
							if (!tickedi[i] && accepted[i][j]) {
								ticked = false;
								tickedi[i] = true;

							}

						}

					}
				}
				for (int i = 1; i < matrixSize; i++) {
					cout << tickedi[i] << "|";
				}
				cout << "\n";
				for (int i = 1; i < matrixSize; i++) {
					cout << tickedj[i] << "|";
				}
				cout << "\n";
				cout << "\n";
			}
		}

		for (int i = 0; i < matrixSize; i++) {
			if (tickedi[i]) {
				tickedi[i] = false;
			} else
				tickedi[i] = true;
		}

		for (int i = 1; i < matrixSize; i++) {
			cout << tickedi[i] << "|";
		}
		cout << "\n";
		for (int i = 1; i < matrixSize; i++) {
			cout << tickedj[i] << "|";
		}
		cout << "\n";
		cout << "\n";
		cout << "all ticked\n";
		int minT = -1;

		for (int i = 1; i < matrixSize; i++) {
			for (int j = 1; j < matrixSize; j++) {
				if ((matrix[i][j] < minT || minT == -1) && !tickedi[i]
				                                                    && !tickedj[j]) {
					minT = matrix[i][j];
				}

			}
		}
		for (int i = 1; i < matrixSize; i++) {
			for (int j = 1; j < matrixSize; j++) {
				if (!tickedi[i] && !tickedj[j]) {
					matrix[i][j] -= minT;
				}
				if (tickedi[i] && tickedj[j]) {
					matrix[i][j] += minT;
				}

			}
		}

		cout << "minT = " << minT << endl;
		//print
		for (int i = 0; i < matrixSize; i++) {
			for (int j = 0; j < matrixSize; j++) {
				cout << matrix[i][j] << "|";
			}
			cout << endl;
		}

		cout << "subtractiosn and additions compelted\n";

		for (int i = 1; i < matrixSize; i++) {

			int aci = matrix[i][0];
			for (int j = 1; j < matrixSize; j++) {

				if (accepted[i][j]) {
					int acj = matrix[0][j];
					for (int c = 0; c < vertexSet[acj - 1]->adj.size(); c++) {
						if (vertexSet[acj - 1]->adj[c].dest->info.getId()
								== aci) {
							vertexSet[acj - 1]->adj[c].proposed = true;
						}
					}
				}
			}
		}
		cout << "graph updated\n";

	}

}
