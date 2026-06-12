package frgp.utn.edu.ar.appmobile_controles_tabpage;

import android.os.Bundle;

import androidx.fragment.app.Fragment;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.GridView;

import java.util.ArrayList;

import adapter.GridPersonaAdapter;
import clases.Persona;


public class fragmentGridview extends Fragment {

    private ArrayList<Persona> lista = new ArrayList<>();
    private GridView gridView;
    public fragmentGridview() {
        // Required empty public constructor
    }

    public static fragmentGridview newInstance(String param1, String param2) {
        fragmentGridview fragment = new fragmentGridview();
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
        // Inflate the layout for this fragment
        View view = inflater.inflate(R.layout.fragment_gridview, container, false);

        lista.add(new Persona("Pedro"));
        lista.add(new Persona("Juan"));
        lista.add(new Persona("Jose"));
        lista.add(new Persona("Luis"));
        lista.add(new Persona("Maria"));
        lista.add(new Persona("Pupi"));
        lista.add(new Persona("Fer"));
        lista.add(new Persona("Mario"));
        lista.add(new Persona("Elena"));

        GridPersonaAdapter adapter = new GridPersonaAdapter(getContext(), lista);
        gridView = view.findViewById(R.id.gridViewPersonas);
        gridView.setAdapter(adapter);
        return view;
    }

}