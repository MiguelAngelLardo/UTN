package adapter;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.TextView;

import java.util.List;

import clases.Persona;
import frgp.utn.edu.ar.appmobile_controles_tabpage.R;

public class GridPersonaAdapter extends BaseAdapter {

    private List<Persona> elementos;

    public GridPersonaAdapter(Context context, List<Persona> elementos) {
        this.elementos = elementos;
    }

    @Override
    public int getCount() {
        return elementos.size();
    }

    @Override
    public Persona getItem(int position) {
        return elementos.get(position);
    }

    @Override
    public long getItemId(int position) {
        return position;
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        LayoutInflater inflater= LayoutInflater.from(parent.getContext());
        View view = convertView;
        if (convertView == null){
            view = inflater.inflate(R.layout.gridview_item_template,null);
        }
        TextView txtNombre = (TextView) view.findViewById(R.id.txtNombreGrid);
        txtNombre.setText(getItem(position).getNombre());
        return view;
    }
}