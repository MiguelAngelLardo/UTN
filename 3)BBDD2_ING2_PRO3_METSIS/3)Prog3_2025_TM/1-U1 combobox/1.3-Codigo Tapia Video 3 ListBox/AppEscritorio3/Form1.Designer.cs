
namespace AppEscritorio3
{
    partial class Form1
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
            this.lblNombreApellido = new System.Windows.Forms.Label();
            this.txtNombreApellido = new System.Windows.Forms.TextBox();
            this.btnAgregar = new System.Windows.Forms.Button();
            this.lbPersonas = new System.Windows.Forms.ListBox();
            this.btnSeleccionado = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // lblNombreApellido
            // 
            this.lblNombreApellido.AutoSize = true;
            this.lblNombreApellido.Location = new System.Drawing.Point(187, 111);
            this.lblNombreApellido.Name = "lblNombreApellido";
            this.lblNombreApellido.Size = new System.Drawing.Size(133, 13);
            this.lblNombreApellido.TabIndex = 0;
            this.lblNombreApellido.Text = "Ingrese Nombre y Apellido:";
            // 
            // txtNombreApellido
            // 
            this.txtNombreApellido.Location = new System.Drawing.Point(323, 108);
            this.txtNombreApellido.Name = "txtNombreApellido";
            this.txtNombreApellido.Size = new System.Drawing.Size(221, 20);
            this.txtNombreApellido.TabIndex = 1;
            // 
            // btnAgregar
            // 
            this.btnAgregar.Location = new System.Drawing.Point(567, 108);
            this.btnAgregar.Name = "btnAgregar";
            this.btnAgregar.Size = new System.Drawing.Size(75, 23);
            this.btnAgregar.TabIndex = 2;
            this.btnAgregar.Text = "Agregar";
            this.btnAgregar.UseVisualStyleBackColor = true;
            this.btnAgregar.Click += new System.EventHandler(this.btnAgregar_Click);
            // 
            // lbPersonas
            // 
            this.lbPersonas.FormattingEnabled = true;
            this.lbPersonas.Location = new System.Drawing.Point(190, 150);
            this.lbPersonas.Name = "lbPersonas";
            this.lbPersonas.SelectionMode = System.Windows.Forms.SelectionMode.MultiSimple;
            this.lbPersonas.Size = new System.Drawing.Size(452, 199);
            this.lbPersonas.TabIndex = 3;
            // 
            // btnSeleccionado
            // 
            this.btnSeleccionado.Location = new System.Drawing.Point(511, 364);
            this.btnSeleccionado.Name = "btnSeleccionado";
            this.btnSeleccionado.Size = new System.Drawing.Size(131, 23);
            this.btnSeleccionado.TabIndex = 4;
            this.btnSeleccionado.Text = "Mostrar seleccionado";
            this.btnSeleccionado.UseVisualStyleBackColor = true;
            this.btnSeleccionado.Click += new System.EventHandler(this.btnSeleccionado_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.btnSeleccionado);
            this.Controls.Add(this.lbPersonas);
            this.Controls.Add(this.btnAgregar);
            this.Controls.Add(this.txtNombreApellido);
            this.Controls.Add(this.lblNombreApellido);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lblNombreApellido;
        private System.Windows.Forms.TextBox txtNombreApellido;
        private System.Windows.Forms.Button btnAgregar;
        private System.Windows.Forms.ListBox lbPersonas;
        private System.Windows.Forms.Button btnSeleccionado;
    }
}

