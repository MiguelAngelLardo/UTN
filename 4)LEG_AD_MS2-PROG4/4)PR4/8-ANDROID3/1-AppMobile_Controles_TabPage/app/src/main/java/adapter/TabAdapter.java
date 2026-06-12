package adapter;

import androidx.annotation.NonNull;
import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentActivity;
import androidx.viewpager2.adapter.FragmentStateAdapter;

import frgp.utn.edu.ar.appmobile_controles_tabpage.fragmentGridview;
import frgp.utn.edu.ar.appmobile_controles_tabpage.fragmentListview;
import frgp.utn.edu.ar.appmobile_controles_tabpage.fragmentSpinner;

public class TabAdapter extends FragmentStateAdapter {

    public TabAdapter(@NonNull FragmentActivity fragmentActivity) {
        super(fragmentActivity);
    }

    @NonNull
    @Override
    public Fragment createFragment(int position) {

        switch (position) {
            case 0:
                return new fragmentSpinner();
            case 1:
                return new fragmentListview();
            case 2:
                return new fragmentGridview();
        }
        return null;
    }

    @Override
    public int getItemCount() {
        return 3;
    }
}
