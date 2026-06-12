package adapter;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.TextView;
import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import java.util.List;
import clases.DiaHorario;
import frgp.utn.edu.ar.appmobile_controles_tabpage.R;

public class SpinnerDiaHorarioAdapter extends ArrayAdapter<DiaHorario> {

    private final List<DiaHorario> items;

    public SpinnerDiaHorarioAdapter(@NonNull Context context, @NonNull List<DiaHorario> items) {
        super(context, 0, items);
        this.items = items;
    }

    @Override
    public int getCount() {
        return items.size();
    }

    @Nullable
    @Override
    public DiaHorario getItem(int position) {
        return items.get(position);
    }

    @NonNull
    @Override
    public View getView(int position, @Nullable View convertView, @NonNull ViewGroup parent) {
        return createItemView(position, convertView, parent);
    }

    @NonNull
    @Override
    public View getDropDownView(int position, @Nullable View convertView, @NonNull ViewGroup parent) {
        return createItemView(position, convertView, parent);
    }

    private View createItemView(int position, @Nullable View convertView, @NonNull ViewGroup parent) {
        View view = convertView;
        if (view == null) {
            view = LayoutInflater.from(getContext())
                    .inflate(R.layout.spinner_item_template, parent, false);
        }

        TextView txtDia = view.findViewById(R.id.dia);
        TextView txthorario = view.findViewById(R.id.horario);

        DiaHorario item = items.get(position);

        txtDia.setText(item.getDia());
        txthorario.setText(item.getHorario());

        return view;
    }

}
