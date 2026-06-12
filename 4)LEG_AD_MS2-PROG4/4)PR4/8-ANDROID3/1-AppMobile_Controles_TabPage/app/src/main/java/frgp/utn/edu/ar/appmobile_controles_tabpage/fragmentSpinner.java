package frgp.utn.edu.ar.appmobile_controles_tabpage;

import android.os.Bundle;

import androidx.fragment.app.Fragment;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.Spinner;
import android.widget.TextView;

import java.util.ArrayList;

import adapter.SpinnerDiaHorarioAdapter;
import clases.DiaHorario;

public class fragmentSpinner extends Fragment {

    private Spinner spinner;
    private TextView txtResultado;
    private ArrayList<DiaHorario> lista = new ArrayList<>();

    public fragmentSpinner() {
        // Required empty public constructor
    }

    public static fragmentSpinner newInstance(String param1, String param2) {
        fragmentSpinner fragment = new fragmentSpinner();
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
         View view =  inflater.inflate(R.layout.fragment_spinner, container, false);
         spinner = (Spinner) view.findViewById(R.id.spinner);
         txtResultado = (TextView) view.findViewById(R.id.txtResultado);

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
        spinner.setAdapter(adapter);

        spinner.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parent, View v, int position, long id) {
                DiaHorario seleccionado = (DiaHorario) parent.getItemAtPosition(position);
                txtResultado.setText("Resultado: " +
                        seleccionado.getHorario() + " - " + seleccionado.getDia());
            }
            @Override
            public void onNothingSelected(AdapterView<?> parent) {
                txtResultado.setText("Resultado: ");
            }
        });

        return view;
    }
}