namespace Ej9_Listview
{
    partial class frmListView
    {
        /// <summary>
        /// Variable del diseñador necesaria.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpiar los recursos que se estén usando.
        /// </summary>
        /// <param name="disposing">true si los recursos administrados se deben desechar; false en caso contrario.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código generado por el Diseñador de Windows Forms

        /// <summary>
        /// Método necesario para admitir el Diseñador. No se puede modificar
        /// el contenido de este método con el editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(frmListView));
            this.lvCarpetas = new System.Windows.Forms.ListView();
            this.imageListLarge = new System.Windows.Forms.ImageList(this.components);
            this.imageListSmall = new System.Windows.Forms.ImageList(this.components);
            this.gbModoVista = new System.Windows.Forms.GroupBox();
            this.rbTitulo = new System.Windows.Forms.RadioButton();
            this.rbDetalle = new System.Windows.Forms.RadioButton();
            this.rbLista = new System.Windows.Forms.RadioButton();
            this.rbSmall = new System.Windows.Forms.RadioButton();
            this.rbLarge = new System.Windows.Forms.RadioButton();
            this.lblActualdir = new System.Windows.Forms.Label();
            this.btnAtras = new System.Windows.Forms.Button();
            this.gbModoVista.SuspendLayout();
            this.SuspendLayout();
            // 
            // lvCarpetas
            // 
            this.lvCarpetas.HideSelection = false;
            this.lvCarpetas.LargeImageList = this.imageListLarge;
            this.lvCarpetas.Location = new System.Drawing.Point(12, 55);
            this.lvCarpetas.Name = "lvCarpetas";
            this.lvCarpetas.Size = new System.Drawing.Size(391, 242);
            this.lvCarpetas.SmallImageList = this.imageListSmall;
            this.lvCarpetas.TabIndex = 0;
            this.lvCarpetas.UseCompatibleStateImageBehavior = false;
            this.lvCarpetas.View = System.Windows.Forms.View.Details;
            this.lvCarpetas.ItemActivate += new System.EventHandler(this.lvCarpetas_ItemActivate);
            // 
            // imageListLarge
            // 
            this.imageListLarge.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("imageListLarge.ImageStream")));
            this.imageListLarge.TransparentColor = System.Drawing.Color.Transparent;
            this.imageListLarge.Images.SetKeyName(0, "folder32.ico");
            this.imageListLarge.Images.SetKeyName(1, "page32.ico");
            // 
            // imageListSmall
            // 
            this.imageListSmall.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("imageListSmall.ImageStream")));
            this.imageListSmall.TransparentColor = System.Drawing.Color.Transparent;
            this.imageListSmall.Images.SetKeyName(0, "folder16.png");
            this.imageListSmall.Images.SetKeyName(1, "page16.png");
            // 
            // gbModoVista
            // 
            this.gbModoVista.Controls.Add(this.rbTitulo);
            this.gbModoVista.Controls.Add(this.rbDetalle);
            this.gbModoVista.Controls.Add(this.rbLista);
            this.gbModoVista.Controls.Add(this.rbSmall);
            this.gbModoVista.Controls.Add(this.rbLarge);
            this.gbModoVista.Location = new System.Drawing.Point(423, 55);
            this.gbModoVista.Name = "gbModoVista";
            this.gbModoVista.Size = new System.Drawing.Size(210, 242);
            this.gbModoVista.TabIndex = 2;
            this.gbModoVista.TabStop = false;
            this.gbModoVista.Text = "Modo de Vista";
            // 
            // rbTitulo
            // 
            this.rbTitulo.AutoSize = true;
            this.rbTitulo.Location = new System.Drawing.Point(7, 112);
            this.rbTitulo.Name = "rbTitulo";
            this.rbTitulo.Size = new System.Drawing.Size(51, 17);
            this.rbTitulo.TabIndex = 4;
            this.rbTitulo.Text = "Titulo";
            this.rbTitulo.UseVisualStyleBackColor = true;
            this.rbTitulo.CheckedChanged += new System.EventHandler(this.rbTitulo_CheckedChanged);
            // 
            // rbDetalle
            // 
            this.rbDetalle.AutoSize = true;
            this.rbDetalle.Checked = true;
            this.rbDetalle.Location = new System.Drawing.Point(7, 89);
            this.rbDetalle.Name = "rbDetalle";
            this.rbDetalle.Size = new System.Drawing.Size(58, 17);
            this.rbDetalle.TabIndex = 3;
            this.rbDetalle.TabStop = true;
            this.rbDetalle.Text = "Detalle";
            this.rbDetalle.UseVisualStyleBackColor = true;
            this.rbDetalle.CheckedChanged += new System.EventHandler(this.rbDetalle_CheckedChanged);
            // 
            // rbLista
            // 
            this.rbLista.AutoSize = true;
            this.rbLista.Location = new System.Drawing.Point(7, 66);
            this.rbLista.Name = "rbLista";
            this.rbLista.Size = new System.Drawing.Size(47, 17);
            this.rbLista.TabIndex = 2;
            this.rbLista.Text = "Lista";
            this.rbLista.UseVisualStyleBackColor = true;
            this.rbLista.CheckedChanged += new System.EventHandler(this.rbLista_CheckedChanged);
            // 
            // rbSmall
            // 
            this.rbSmall.AutoSize = true;
            this.rbSmall.Location = new System.Drawing.Point(7, 43);
            this.rbSmall.Name = "rbSmall";
            this.rbSmall.Size = new System.Drawing.Size(71, 17);
            this.rbSmall.TabIndex = 1;
            this.rbSmall.Text = "SmallIcon";
            this.rbSmall.UseVisualStyleBackColor = true;
            this.rbSmall.CheckedChanged += new System.EventHandler(this.rbSmall_CheckedChanged);
            // 
            // rbLarge
            // 
            this.rbLarge.AutoSize = true;
            this.rbLarge.Location = new System.Drawing.Point(7, 20);
            this.rbLarge.Name = "rbLarge";
            this.rbLarge.Size = new System.Drawing.Size(73, 17);
            this.rbLarge.TabIndex = 0;
            this.rbLarge.Text = "LargeIcon";
            this.rbLarge.UseVisualStyleBackColor = true;
            this.rbLarge.CheckedChanged += new System.EventHandler(this.rbLarge_CheckedChanged);
            // 
            // lblActualdir
            // 
            this.lblActualdir.AutoSize = true;
            this.lblActualdir.Location = new System.Drawing.Point(12, 39);
            this.lblActualdir.Name = "lblActualdir";
            this.lblActualdir.Size = new System.Drawing.Size(85, 13);
            this.lblActualdir.TabIndex = 3;
            this.lblActualdir.Text = "Directorio Actual";
            // 
            // btnAtras
            // 
            this.btnAtras.Location = new System.Drawing.Point(88, 303);
            this.btnAtras.Name = "btnAtras";
            this.btnAtras.Size = new System.Drawing.Size(75, 23);
            this.btnAtras.TabIndex = 4;
            this.btnAtras.Text = "Atras";
            this.btnAtras.UseVisualStyleBackColor = true;
            this.btnAtras.Click += new System.EventHandler(this.btnAtras_Click);
            // 
            // frmListView
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(645, 373);
            this.Controls.Add(this.btnAtras);
            this.Controls.Add(this.lblActualdir);
            this.Controls.Add(this.gbModoVista);
            this.Controls.Add(this.lvCarpetas);
            this.Name = "frmListView";
            this.Text = "ListView";
            this.gbModoVista.ResumeLayout(false);
            this.gbModoVista.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ListView lvCarpetas;
        private System.Windows.Forms.ImageList imageListSmall;
        private System.Windows.Forms.ImageList imageListLarge;
        private System.Windows.Forms.GroupBox gbModoVista;
        private System.Windows.Forms.RadioButton rbTitulo;
        private System.Windows.Forms.RadioButton rbDetalle;
        private System.Windows.Forms.RadioButton rbLista;
        private System.Windows.Forms.RadioButton rbSmall;
        private System.Windows.Forms.RadioButton rbLarge;
        private System.Windows.Forms.Label lblActualdir;
        private System.Windows.Forms.Button btnAtras;
    }
}

