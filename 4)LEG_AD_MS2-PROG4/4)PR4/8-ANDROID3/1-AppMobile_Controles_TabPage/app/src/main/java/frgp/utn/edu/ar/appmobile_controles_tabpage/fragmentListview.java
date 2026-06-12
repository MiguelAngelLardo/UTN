package frgp.utn.edu.ar.appmobile_controles_tabpage;

import android.os.Bundle;
import androidx.fragment.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ListView;
import java.util.ArrayList;
import adapter.SpinnerDiaHorarioAdapter;
import clases.DiaHorario;

public class fragmentListview extends Fragment {

        private ArrayList<DiaHorario> lista = new ArrayList<>();
        private ListView listview;

        public fragmentListview() {
            // Required empty public constructor
        }

        public static fragmentListview newInstance(String param1, String param2) {
            fragmentListview fragment = new fragmentListview();
            Bundle args = new Bundle();
            fragment.setArguments(args);
            return fragment;
        }

        @Override
        public void onCreate(Bundle savedInstanceState) {
            super.onCreate(savedInstanceState);
        }

        @Override
        public View onCreateView(LayoutInflater inflater, ViewGroup container,
                                 Bundle savedInstanceState) {
            View vista =  inflater.inflate(R.layout.fragment_listview, container, false);
            listview = vista.findViewById(R.id.listViewDiaHorario);

            DiaHorario elemento1 = new DiaHorario();
            elemento1.setDia("Lunes");
            elemento1.setHorario("08:00 a 12:00");

            DiaHorario elemento2 = new DiaHorario();
            elemento2.setDia("martes");
            elemento2.setHorario("10:00 a 12:00");

            DiaHorario elemento3 = new DiaHorario();
            elemento3.setDia("miercoles");
            elemento3.setHorario("15:00 a 18:00");

            lista.add(elemento1);
            lista.add(elemento2);
            lista.add(elemento3);

            SpinnerDiaHorarioAdapter adapter = new SpinnerDiaHorarioAdapter(requireContext(),lista);
            listview.setAdapter(adapter);

            return vista;
        }
    }