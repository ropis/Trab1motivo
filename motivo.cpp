#include "MuMaterial.h"

MuMaterial Escolha(MuMaterial* mat){
	int numerorand = Between (0,5);
	long total = mat->NumberOfNotes();
	int half = total/2;
	MuMaterial tmp;
	switch(numerorand){
		case 0:
			mat->ColapsePitch();
			break;
		case 1:
			tmp.Clear();
			tmp = mat->GetNotes(0,half, total-1);
			tmp.ExpandInterval(Between(1,5));
			*mat = mat->GetNotes(0,0,half-1);
			*mat += tmp;
			break;
		case 2:
			mat->Invert();
			break;
		case 3:
			mat->Transpose(5);
			break;
		case 4:
			tmp.Clear();
			tmp = mat->GetNotes(0,half, total-1);
			tmp.ContractInterval(Between(1,5));
			*mat = mat->GetNotes(0,0,half-1);
			*mat += tmp;
			break;
		case 5:
			mat->Retro();
			break;
		default:
			return *mat;
			break;
	}
	
	return *mat;
	
}


int main(void)
{
	MuInit();
	MuMaterial motivo, melodiafinal, mat, mat2, motivomet, motivomet2;
	MuNote nota, pausa;
	int notas[8] = {60,67,65,64,62,64,60,55};
	int i;
	
	nota.SetInstr(1);
	nota.SetAmp(0.7);
	pausa.SetDur(0.2);
	
	for (i=0;i<8;i++){
		nota.SetPitch(notas[i]);
		switch(i){
			case 0:
			nota.SetStart(0);
			nota.SetDur(0.8);
			break;
			case 1:
			nota.SetDur(0.9);
			break;
			case 2:
			nota.SetDur(0.4);
			break;
			case 6:
			nota.SetDur(0.9);
			break;
			case 7:
			nota.SetDur(1);
			break;
			default:
			nota.SetDur(0.4);
			break;			
		}	
		motivo += nota;
	}
	
	int vez=3;
	mat = motivo;
	melodiafinal = motivo;
	while (vez--){
		mat = Escolha(&mat);
		melodiafinal += mat;
		
	}

	
	
	
	/*
	int opcao = Between(0,4);
	long numeronotas;
	numeronotas = motivo.NumberOfNotes();
	cout << "numero de notas: "<<numeronotas << endl;
	int metade = numeronotas/2 -1;
	
	melodiafinal = motivo;
	melodiafinal += pausa;
	motivomet=motivo;
	motivomet2=motivo;
	motivomet = motivomet.GetNotes(0,0,metade-1);
	//motivomet.PlaybackWithCsound("/home/rodrigo/MuM-master/teste");
	motivomet2 = motivomet2.GetNotes(0,metade,numeronotas-1);
	//motivomet2.PlaybackWithCsound("/home/rodrigo/MuM-master/teste");
	//motivomet2.ExpandInterval(2);
	motivomet2.ColapsePitch();
	motivomet += motivomet2;
	melodiafinal += motivomet;
	melodiafinal.PlaybackWithCsound("/home/rodrigo/MuM-master/teste");
	mat = motivo;
	//motivomet2.PlaybackWithCsound("/home/rodrigo/MuM-master/teste");

	 cout << (motivomet2.LastError()).Message();


	
	
	mat = motivo;
	mat.Invert();
	melodiafinal+=mat;
	int numbers[3] = {2,4};
	float duracao = mat.Dur(); //pega duracao do material
	mat = motivo;
	mat.Fit(duracao*numbers[Between(0,1)]); // muda a duracao do material
	float durafit = mat.Dur();
	melodiafinal+=mat;
	mat.ExpandInterval(1); //adiona 1 ao pitch de cada nota
	melodiafinal += mat;
	mat=motivo;
	mat.ContractInterval(1); //subtrai 1 ao pitch de cada nota
	melodiafinal += mat;
	if(0){
		while (vez--){
			mat = motivo;
			mat.Transpose(Between(5,5));
			melodiafinal += mat;
			melodiafinal += pausa;
		}
	}
*/

	melodiafinal.PlaybackWithCsound("/home/rodrigo/MuM-master/teste");
	melodiafinal.SetDefaultFunctionTables();
	melodiafinal.Score("outFile");
	melodiafinal.Orchestra("outFile");
	return 0;
}
