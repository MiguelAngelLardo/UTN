namespace PRACTICA_8
{
    partial class frmListBoxCheckedListBox
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
            this.clbValores = new System.Windows.Forms.CheckedListBox();
            this.lbSeleccionados = new System.Windows.Forms.CheckedListBox();
            this.btnMover = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // clbValores
            // 
            this.clbValores.CheckOnClick = true;
            this.clbValores.FormattingEnabled = true;
            this.clbValores.Items.AddRange(new object[] {
            "Uno",
            "Dos",
            "Tres",
            "Cuatro",
            "Cinco",
            "Seis",
            "Siete",
            "Ocho",
            "Nueve"});
            this.clbValores.Location = new System.Drawing.Point(31, 57);
            this.clbValores.Name = "clbValores";
            this.clbValores.Size = new System.Drawing.Size(335, 361);
            this.clbValores.TabIndex = 0;
            // 
            // lbSeleccionados
            // 
            this.lbSeleccionados.CheckOnClick = true;
            this.lbSeleccionados.FormattingEnabled = true;
            this.lbSeleccionados.Location = new System.Drawing.Point(487, 57);
            this.lbSeleccionados.Name = "lbSeleccionados";
            this.lbSeleccionados.Size = new System.Drawing.Size(301, 361);
            this.lbSeleccionados.TabIndex = 1;
            // 
            // btnMover
            // 
            this.btnMover.Location = new System.Drawing.Point(393, 181);
            this.btnMover.Name = "btnMover";
            this.btnMover.Size = new System.Drawing.Size(75, 23);
            this.btnMover.TabIndex = 2;
            this.btnMover.Text = "Mover";
            this.btnMover.UseVisualStyleBackColor = true;
            this.btnMover.Click += new System.EventHandler(this.btnMover_Click);
            // 
            // frmListBoxCheckedListBox
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.btnMover);
            this.Controls.Add(this.lbSeleccionados);
            this.Controls.Add(this.clbValores);
            this.Name = "frmListBoxCheckedListBox";
            this.Text = "ListBox y CheckedListBox";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.CheckedListBox clbValores;
        private System.Windows.Forms.CheckedListBox lbSeleccionados;
        private System.Windows.Forms.Button btnMover;
    }
}

